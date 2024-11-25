//******************************************************************************
// File Name: main.c
//
// Version: 1.10
//
//******************************************************************************

// PSoC5
#include <device.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// FreeRTOS
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
// API
#include "USBUART_FIFO.h"
#include "rot.h"

// Project Defines
#define FALSE  0
#define TRUE   1

// Resources for FreeRTOS
#define TASK_STACK_LED      128
#define TASK_STACK_USBUART  256
#define TASK_STACK_ROT      128
#define TASK_STACK_KEY      128
#define TASK_STACK_TONE     512

#define TASK_PRIORITY_LED  (tskIDLE_PRIORITY + 4)
#define TASK_PRIORITY_ROT  (tskIDLE_PRIORITY + 3)
#define TASK_PRIORITY_KEY  (tskIDLE_PRIORITY + 3)
#define TASK_PRIORITY_TONE (tskIDLE_PRIORITY + 2)
#define TASK_PRIORITY_USBUART (tskIDLE_PRIORITY + 1)

#define USBUART_TIMEOUT 2000000                 // Timeout for USB Connection (adjustment might be required)

// Function Prototypes
void prvHardwareSetup(void);
void Initialize(void);
void timerISR_1_Routine(void);  // watchdog timer interrupt
void Filter_Handler(void);      // filter interrupt
void DMA_Config(void);
void Task_LED   (void *pvParameters);
void Task_USBUART  (void *pvParameters);
void Task_ROT   (void *pvParameters);
void Task_TONE  (void *pvParameters);
void ReadUSB (void);
void FactorySetup (void);
void Initialize (void);
void ProcessComRx (void);

// Global variables for FreeRTOS
xQueueHandle xQueue_ROT;        // Queue Data from Task_ROT(ROT_ENC_Handler)
xQueueHandle xQueue_TONE;       // Queue Data from CY_ISR(Filter_Handler)
xQueueHandle xQueue_CHAR;       // Queue Data from Task_TONE
xQueueHandle xQueue_WPM;        // Queue Data from Task_TONE
xQueueHandle xQueue_TH;         // Queue Data from Task_TONE

//#define CORDIC
// Global variables Filter interrupt
#ifndef CORDIC
// SIGN(sin(2pi*(fd/fs)*n) = SIGN(sin(2pi*n/20)) = [1 @cntr=0~9 | 0 @cntr=10~19]
// SIGN(cos(2pi*(fd/fs)*n) = SIGN(cos(2pi*n/20)) = [1 @cntr=0~4,15~19 | 0 @cntr=5~14]
#define SIGN_CNTR_CYCLE     20
uint8   sign_cntr = 0;          // 20 counter
const int8 Sign_Sin[20] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
const int8 Sign_Cos[20] = { 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1 };
int32  acc_v_sin = 0;      // accumulator of RMS for 80 times
int32  acc_v_cos = 0;      // accumulator of RMS for 80 times
#endif
int32   IDelay[8];
uint8   IDelayPtr;
uint32  acc_Vrms = 0;      // accumulator of RMS for 80 times
uint8   int_cntr = 0;      // 80 counter (80 / 16kbps =  5 ms)
uint8   debouunce_cntr = 2;      // debounce counter = 2

// Global variables for USBUART
uint8	ComRxCmd [32];				// remote command rx buffer
uint8	ComRxPtr;					// pointer into com rx buffer
uint8	UsbTxBuffer [80];			// USB transmit buffer
uint8	UsbRxBuffer [256];			// USB receive buffer


extern char MorseCharTraslateTable [];
//extern uint8 WPM_Table[];

//******************************************************************************
// Function Name: main
//******************************************************************************
//
// Summary:
//  Main function performs following functions:
//   1: Enables global interrupts
//   2: Start all components on the schematic
//   3: Calls a function to configure DMA
//
// Parameters:
//  None.
//
// Return:
//  None.
//
//******************************************************************************
int main()
{
    prvHardwareSetup();
    
	Initialize();

    // Create Queue
    xQueue_ROT    = xQueueCreate(8, 1);     // 8 x 1byte
    xQueue_TONE   = xQueueCreate(8, 1);     // 8 x 1bytes
    xQueue_CHAR   = xQueueCreate(8, 1);     // 8 x 1bytes
    xQueue_WPM    = xQueueCreate(1, 1);     // 1 x 1bytes
    xQueue_TH     = xQueueCreate(1, 1);     // 1 x 1bytes
    
    // Create Tasks
    xTaskCreate(Task_LED, "LED", TASK_STACK_LED, NULL, TASK_PRIORITY_LED, NULL);
    xTaskCreate(Task_USBUART, "USBUART", TASK_STACK_USBUART, NULL, TASK_PRIORITY_USBUART, NULL);
    xTaskCreate(Task_ROT, "ROT", TASK_STACK_ROT, NULL, TASK_PRIORITY_ROT, NULL);
    xTaskCreate(Task_TONE, "TONE", TASK_STACK_TONE, NULL, TASK_PRIORITY_TONE, NULL);

    // Start RTOS Kernel
    vTaskStartScheduler();

    for(;;)
    {
        
        // Place your application code here.
        
    }
} // End of main

//----------------------------------------------------------------------------
//
//	Initialize and configure hardware, initialize variables
//
//----------------------------------------------------------------------------
void Initialize (void)
{

    // Watchdog Timer Enable.
    timerISR_1_StartEx(timerISR_1_Routine);
    Timer_1_Start();
    CyWdtStart(CYWDT_1024_TICKS,CYWDT_LPMODE_NOCHANGE);
    
    // Initialize API
    Init_ROT();

    // Start all components used on schematic
    ADC_DelSig_IRQ_Start();
    PGA_1_Start(); 
    ADC_DelSig_Start();
    ADC_DelSig_StartConvert();
    VDAC8_Start();
    Opamp_1_Start();
    Opamp_2_Start();
    Filter_Start();
    // set the Tone Threshold to max.   
    Control_Reg_1_Write(0xFF);
    
    // User-implemented function to set-up DMA
    DMA_Config();

    // Initiarize Filter Interrupt
    for (uint8 i = 0; i < 8; i++)
       IDelay[i] = 0;
    IDelayPtr = 0;
    debouunce_cntr = 0;
    // Enable Filter Interrupt
    isr_filter_StartEx(Filter_Handler);    

    // Enable Global Interrupts
    CYGlobalIntEnable;
    
    // Initialize the I2C CLCD
    //I2C_1_Start();
    //I2C_CLCD_Start();
    //I2C_CLCD_Position(0u,0u);
    //                   "0123456789012345"
    //I2C_CLCD_PrintString("CW_Decoder      ");
    //I2C_CLCD_Position(1u,0u);
    //I2C_CLCD_PrintString("getting started" );
    CyDelay(1000u);
}

//---------------------------------------------------------------------------
void prvHardwareSetup( void )
{
    // Port layer functions that need to be copied into the vector table.
    extern void xPortPendSVHandler( void );
    extern void xPortSysTickHandler( void );
    extern void vPortSVCHandler( void );
    extern cyisraddress CyRamVectors[];

	// Install the OS Interrupt Handlers.
	CyRamVectors[ 11 ] = ( cyisraddress ) vPortSVCHandler;
	CyRamVectors[ 14 ] = ( cyisraddress ) xPortPendSVHandler;
	CyRamVectors[ 15 ] = ( cyisraddress ) xPortSysTickHandler;
    
}
//---------------------------------------------------------------------------

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	// The stack space has been execeeded for a task, considering allocating more.
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
//---------------------------------------------------------------------------

void vApplicationMallocFailedHook( void )
{
	/* The heap space has been execeeded. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
//---------------------------------------------------------------------------

//******************************************************************************
//  Watchdog Timer ISR
//******************************************************************************
uint8 tFlag;

CY_ISR(timerISR_1_Routine)
{
    tFlag = Timer_1_ReadStatusRegister();
    /* Clear WDT */
    CyWdtClear();
}


//***************************************************************************
//	Task_LED
//***************************************************************************
void Task_LED(void *pvParameters)
{
    // Block time in (ms)
    const portTickType OnDelay = 1000 / portTICK_RATE_MS;
    const portTickType OffDelay = 1000 / portTICK_RATE_MS;
    
    //Debug
    char character;

    while(1)
    {
        LED_1_Write(1);
        vTaskDelay(OnDelay);

        LED_1_Write(0);
        vTaskDelay(OffDelay);
        
        //Debug
        //character = '3';
        //xQueueSend(xQueue_CHAR, &character, 0);

        
    }
}



//***************************************************************************
// Function Name: DMA_Config
//***************************************************************************
//
// Summary:
//  Initializes and sets up DMA for use (generated by DMA Wizard)
//
// Parameters:
//  None.
//
// Return:
//  None.
//
//***************************************************************************
// DMA
#define REQUEST_PER_BURST        (1u)
#define BYTES_PER_BURST          (1u)
#define UPPER_SRC_ADDRESS        CYDEV_PERIPH_BASE
#define UPPER_DEST_ADDRESS       CYDEV_PERIPH_BASE

void DMA_Config(void)
{
    // Declare variable to hold the handle for DMA channel
    uint8 channelHandle;

    // Declare DMA Transaction Descriptor for memory transfer into
    // Filter Channel.
    uint8 tdChanA;

    // Configure the DMA to Transfer the data in 1 burst with individual trigger
    // for each burst.
    channelHandle = DMA_DmaInitialize(BYTES_PER_BURST, REQUEST_PER_BURST,
                                        HI16(UPPER_SRC_ADDRESS), HI16(UPPER_DEST_ADDRESS));

    // This function allocates a TD for use with an initialized DMA channel
    tdChanA = CyDmaTdAllocate();

    // Configure the tdChanA to transfer 1 byte with no next TD
    CyDmaTdSetConfiguration(tdChanA, 1u, DMA_INVALID_TD, 0u);

    // Set the source address as ADC_DelSig and the destination as
    // Filter Channel A.
    CyDmaTdSetAddress(tdChanA, LO16((uint32)ADC_DelSig_DEC_SAMP_PTR), LO16((uint32)Filter_STAGEAH_PTR));

    // Set tdChanA to be the initial TD associated with channelHandle
    CyDmaChSetInitialTd(channelHandle, tdChanA);

    // Enable the DMA channel represented by channelHandle and preserve the TD
    CyDmaChEnable(channelHandle, 1u);
}


//*******************************************************************************
// Filter Handler ISR
//*******************************************************************************
// Interrupt generated on Filter sample-ready. Interrupt handle:Filter_Handler
//
// Summary:
//  The interrupt performs following functions:
//   1: Reads the left-justified register for Filter Channel A
//   2: Converts it into an unsigned RMS value
//   3: Debouncing Tone signal every 5 msec
//   4: Send debounced Tone signal to the TONE queue
//
//*******************************************************************************
// Filter Handler
#ifndef CORDIC
    #define MLT_A  9           // V(mV) << 10 , V < 5000mV
#else
    #define MLT_A  10           // V(mV) << 10 , V < 5000mV
#endif
#define V_OFFSET    128u    // 2.048 V = 128 * 16 mV/bit
#define SAMPLE_PER_SEC          16                // 16 ksps
#define SAMPLES_TO_PROCESS_N    SAMPLE_PER_SEC * 5  // 1/(16ksps) * 80 = 5 ms
//#define TONE_THRESHOLD          100     // threshold of accumulated signal RMS
#define TONE_THRESHOLD          500     // threshold of accumulated signal RMS
#define DEBOUNCE_THRESHOLD      2       // debounce time = 5 * (2 + 1) = 15 ms
//#define DEBOUNCE_THRESHOLD      3       // debounce time = 5 * (3 + 1) = 20 ms

   
CY_ISR(Filter_Handler)
{
    int8    filter;
    uint8   tone = 0;       // debounced tone signal
    uint8   i;
#ifndef CORDIC
#else
    int32   Ik0, Qk0;       // ampletude of filtered rx level << MltA
    int32   Ikn, Qkn;       // used in CORDIC calculation
#endif

    // Debug
    MON_ISR_Write(1u);

    filter = Filter_Read8(Filter_CHANNEL_A);
    // clear flags except INTR_HOLDB
    Filter_SR_REG = Filter_ALL_INTR & (~Filter_CHANNEL_B_INTR);
    // Send the Data to Queue
    //xQueueSendFromISR(xQueue_FILTER, &filter, NULL);
    
#ifndef CORDIC
    //******************************
    //  CORRELATOR
    //******************************

    int_cntr++;     // 5 ms counter
    sign_cntr++;    // 1.25ms (1 cycle of 800Hz) counter
    if (sign_cntr == SIGN_CNTR_CYCLE)
        sign_cntr = 0;
    
    acc_v_sin += Sign_Sin[sign_cntr] * (int32)filter << MLT_A;
    acc_v_cos += Sign_Cos[sign_cntr] * (int32)filter << MLT_A;

    //***************************
    //  Tone debouncing (5 ms)
    //***************************
    if (int_cntr == SAMPLES_TO_PROCESS_N)     // 1/(16ksps) * 80 = 5 ms
    {
        //acc_Vrms = sqrt(pow(acc_v_sin, 2) + pow(acc_v_cos, 2));
        acc_Vrms = pow(acc_v_sin, 2) + pow(acc_v_cos, 2);
        // over the threshold ?
        //if ((acc_Vrms >> MLT_A) > TONE_THRESHOLD)
        if (acc_Vrms > 0x80000000)
        {
            // signal detect
            if (debouunce_cntr > DEBOUNCE_THRESHOLD)
            {
                tone = 1;
                LED_Write(1u);
            }
            else
                debouunce_cntr++;
        }
        else
        {
            // No signal
            if (debouunce_cntr == 0)
            {
                tone = 0;
                LED_Write(0u);
            }
            else
                debouunce_cntr--;
        }
        // Send the Data to Queue
        xQueueSendFromISR(xQueue_TONE, &tone, NULL);
        
        // Waveform Monitor
        VDAC8_SetValue((int8)(acc_Vrms >> MLT_A));      // Morse Code
        // Init. variables
        acc_Vrms = 0;
        acc_v_sin = 0;
        acc_v_cos = 0;
        int_cntr = 0;
        sign_cntr = 0;
    }
#else    
    //******************************
    //  CORDIC
    //******************************
    Ik0 = (int32)filter << MLT_A;             // I input
    IDelay[IDelayPtr] = Ik0;                  // put shifter
    // Q input = I + pi/2
    // 2pi = 16ksps / 800Hz = 20 samples, pi/2 = 5 sample
    Qk0 = IDelay[(IDelayPtr - 5) & 0x07];
    // increment the pointer
    IDelayPtr = (IDelayPtr + 1) & 0x07;
    
    if (Ik0 < 0)                     // I axsis > 0 for CORDIC
        Ik0 = -Ik0;
    Ikn = 0;     // (n)th of Real Value     * 2^MLT_A
    Qkn = 0;     // (n)th of Imaginal Value * 2^MLT_A
    // CORDIC(12bit)
    for (i = 0; i < 12; i++)
    {
        if (Qk0 >= 0)
        {
            Ikn = Ik0 + (Qk0 >> i);
            Qkn = Qk0 - (Ik0 >> i);
        }
        else
        {
            Ikn = Ik0 - (Qk0 >> i);
            Qkn = Qk0 + (Ik0 >> i);
        }
        Ik0 = Ikn;
        Qk0 = Qkn;
    }
    acc_Vrms += Ikn;   // rms
    
    int_cntr++; // 5 ms counter

    // Waveform Monitor
    //VDAC8_SetValue((int8)(Ikn >> MLT_A));      // Morse Code

    //***************************
    //  Tone debouncing (5 ms)
    //***************************
    if (int_cntr == SAMPLES_TO_PROCESS_N)     // 1/(16ksps) * 80 = 5 ms
    {
        // over the threshold ?
        //if ((acc_Vrms >> MLT_A) > (uint32)(Status_Reg_1_Read() << 3))
        if ((acc_Vrms >> MLT_A) > TONE_THRESHOLD)
        {
            // signal detect
            if (debouunce_cntr > DEBOUNCE_THRESHOLD)
            {
                tone = 1;
                LED_Write(1u);
            }
            else
                debouunce_cntr++;
        }
        else
        {
            // No signal
            if (debouunce_cntr == 0)
            {
                tone = 0;
                LED_Write(0u);
            }
            else
                debouunce_cntr--;
        }
        // Send the Data to Queue
        xQueueSendFromISR(xQueue_TONE, &tone, NULL);
        
        // Waveform Monitor
        VDAC8_SetValue((int8)(acc_Vrms >> (MLT_A + 3)));      // Morse Code
        // Init. variables
        acc_Vrms = 0;
        int_cntr = 0;
    }
#endif
    // Debug
    MON_ISR_Write(0u);
}


//***************************************************************************
//	Task_TONE
//***************************************************************************
// Tone Detection
#define DIT_DEFAULT             12			// Default values for 20WPM
#define DAH_DEFAULT             36	
#define THRESHOLD_DEFAULT       (DAH_DEFAULT + DIT_DEFAULT)/2
#define NB_LEARN_PERIODS      5 * 255
//#define NB_LEARN_PERIODS        3 * 255
#define DAH_UPPER_LIMIT         18    // 18 * 5 msec (40WPM)
#define DAH_LOWER_LIMIT         75    // 75 * 5 msec (10WPM)

void Task_TONE(void *pvParameters)
{
    uint8   tone = 0;           // received from xQueue_TONE, 0: No-tone, 1: Tone detected
    uint8   last_tone = 0;      // last received tone
    uint8   tone_flag = 0;      // Tone detected
    uint8   pause_flag = 0;     // Processing symbol
    uint8   reset_flag = 0;     // Idle counter expired
    uint8   i;
    const   portTickType xDelay = 2 / portTICK_RATE_MS;

    uint16  _Counter5ms = 0;    // 5ms counter

    uint16  ditptr;     // BLK		1		; Pointer to DIT buffer
    uint16  ditvals[4]; // BLK		4		; DIT buffer
    uint16  ditave;     // BLK		1		; Average of DIT periods
    uint16  dahptr;     // BLK		1		; Pointer to DASH buffer
    uint16  dahvals[4]; // BLK		4		; DASH buffer
    uint16  dahave;     // BLK		1		; Average of DASH periods
    uint16  new_dahave; // BLK		1		; calculated Average of DASH periods

    uint16  threshold;  // BLK		1		; Symbol detection threshold	
    uint16  new_threshold;  // BLK		1	; Symbol detection threshold	
    uint16  period;     // BLK		1		; Gets last period measurement
    uint16  code;       // BLK		1		; Variables for decoding: code mask
    uint16  mask;       // BLK		1		; ""
    uint16  character;  // BLK		1		; Last decoded character
    
    uint16  dit_cntr;   // watch doc for 16 continuous dit.
    uint16  dah_cntr;   // watch doc for 16 continuous dah.
    
    //  code 0bxxxx xxxx
    //      bit0    : 1st symbol    0: DASH, 1: DIT
    //      bit1    : 2nd symbol    0: DASH, 1: DIT
    //      bit2    : 3rd symbol    0: DASH, 1: DIT
    //      bit3    : 4th symbol    0: DASH, 1: DIT
    //      bit4    : 5th symbol    0: DASH, 1: DIT
    //      bit5    : 6th symbol    0: DASH, 1: DIT
    //      end of symbol (bit2 ~ bit6) = mask << 1
    //
    //      (e.g.)
    //      'w' : .-- (+end of symbol)
    //              2^0*1 + 2^1*0 + 2^2*0 + 2^3*1 = 0b0000 1001 = 9 
    //      'f' : ..-. (+end of symbol)
    //              2^0*1 + 2^1*1 + 2^2*0 + 2^3*1 + 2^4*1 = 0b0001 1011 = 27 
    //
    //  mask 0bxxxx xxxx
    //      bit0    : 1st symbol    0b0000 0001 (initial value)
    //      bit1    : 2nd symbol    0b0000 0010 (processing symbol)
    //      bit2    : 3rd symbol    0b0000 0100 (processing symbol)
    //      bit3    : 4th symbol    0b0000 1000 (processing symbol)
    //      bit4    : 5th symbol    0b0001 0000 (processing symbol)
    //      bit5    : 6th symbol    0b0010 0000 (processing symbol)
    //
    
    reset_flag = 1;
    
    // Main Loop
    while(1)
    {
        TONE_Write(1);  // Debug

        if (reset_flag == 1)
        {
            // reset learning (20WPM)
            reset_flag = 0;

            for (i = 0; i < 4; i++)
               ditvals[i] = DIT_DEFAULT;
            ditptr = 0;
            ditave = DIT_DEFAULT;
            for (i = 0; i < 4; i++)
               dahvals[i] = DAH_DEFAULT;
            dahptr = 0;
            dahave = DAH_DEFAULT;
            new_dahave = DAH_DEFAULT;
            dit_cntr = 0;
            dah_cntr = 0;

            code = 0x00;           // initial code
            mask = 0x01;           // initial position : 0b00000001

            threshold = THRESHOLD_DEFAULT;
            
            // display the reset state on CLCD
            xQueueSend(xQueue_WPM, &code, 0);
            xQueueSend(xQueue_TH, &threshold, 0);
            // send ESC code to clear the line
            character = 0x1b;
            xQueueSend(xQueue_CHAR, &character, 0);
        }
        
        if (uxQueueMessagesWaiting(xQueue_TONE) > 0)
        {
            xQueueReceive(xQueue_TONE, &tone, 0);
            // TOne Monitor
            //TONE_Write(tone);
            period = (uint8)_Counter5ms;
            
            if (tone == 0 && last_tone > 0)    // Tone detected
            {
                tone_flag = 1;
                _Counter5ms = 0;
            }
            else if (tone > 0 && last_tone == 0)    // Pause detected
            {
                pause_flag = 1;
                _Counter5ms = 0;
            }
            // if there is a processing symbol, then set pause flag to complete cnvert.
            else if (mask > 1 && _Counter5ms > threshold * 4)
            {
                pause_flag = 1;
                _Counter5ms = 0;
            }
            else
            {
                // increment 5ms counter
                _Counter5ms++;
                
                //if ((_Counter5ms % 0x80) == 0)
                if ((_Counter5ms % 0x100) == 0)     // koseki(2021.8.10)
                {
                    character = ' ';
                    xQueueSend(xQueue_CHAR, &character, 0);
                }
                if (_Counter5ms > NB_LEARN_PERIODS)
                {
                    reset_flag = 1;
                    _Counter5ms = 0;
                }
            }
            // save the last tone
            last_tone = tone;
        }
           
        if (tone_flag == 1)
        {
            tone_flag = 0;
            if (period > threshold)
            {   // DASH
                // if period is valid, then calc. dah average.
                if (period < DAH_LOWER_LIMIT && period > DAH_UPPER_LIMIT)
                {
                    dahvals[dahptr] = period;
                    dahptr = (dahptr + 1) & 0x03;
                    new_dahave = (dahvals[0] + dahvals[1] + dahvals[2] + dahvals[3]) / 4;
                }
                if (new_dahave != dahave)
                {   // dahave is changed
                    dahave = new_dahave;
                    xQueueSend(xQueue_WPM, &dahave, 0);
                }
                dah_cntr++;
                dit_cntr = 0;
            }
            else
            {   // DIT
                code += mask;
                // CalcAveDit
                ditvals[ditptr] = period;
                ditptr = (ditptr + 1) & 0x03;
                ditave = (ditvals[0] + ditvals[1] + ditvals[2] + ditvals[3]) / 4;
                dah_cntr = 0;
                dit_cntr++;
            }
            // Update threshold
            new_threshold = (dahave + ditave) / 2;
            if (new_threshold != threshold)
            {
                threshold = new_threshold;
                xQueueSend(xQueue_TH, &threshold, 0);
            }
            // Shift mask
            if (mask < 0b10000000)
                mask = mask << 1;
            
            //continuous dit or dah check
            if (dah_cntr > 15 || dit_cntr > 15)
                reset_flag = 1;
        }
        
        if (pause_flag == 1)
        {
            pause_flag = 0;
            if (mask > 1 && period > threshold)
            {
                // Pause between characters is detected.
                code += mask;
                // convert code to ASCII code
                if (code > 121)
                    character = '*';
                else
                    character = MorseCharTraslateTable[code];
                xQueueSend(xQueue_CHAR, &character, 0);

                code = 0;    // initial code
                mask = 1;    // initial position : 0b00000001
            }
            if (period > threshold * 3)
            {
                // Pause between words is detected.
                character = ' ';
                xQueueSend(xQueue_CHAR, &character, 0);
            }
        }
        TONE_Write(0);  // Debug
        
        // sleep for 2ms
        vTaskDelay(xDelay);
    }

}


//============================================================================
//
//	Task_USBUART
//
//============================================================================
//
// ISR of int_uartQueue(2kHz clock) interrupt.
//
CY_ISR(int_uartQueue_isr)
{
    uartTxIsr();
    uartRxIsr();
}

// for DEBUG
// 32-bit Decimal table
static const uint32 CYCODE pow10_32[] = {
    0L,
    1L,
    10L,
    100L,
    1000L,
    10000L,
    100000L,
    1000000L,
    10000000L,
    100000000L,
    1000000000L,
};

// for DEBUG
// 32-bit Decimal expression w/o ZERO SUPPRESS
void putdec32(uint32 num, const uint8 nDigits)
{
    uint8       i;
    uint8       k;
    CYBIT       show = 0;

    // The figure length to be expression
    i = sizeof pow10_32 / sizeof pow10_32[0];
    while (--i > 0)
    {             // until unit's place
        // Get the value of i-th degit
        for (k = 0; num >= pow10_32[i]; k++)
        {
            num -= pow10_32[i];
        }
        // i-th degit is vald?
        show = show || (i <= nDigits) || (k != 0);
        if (show)
            putch(k + '0');     // Send i-th degit
    }
}

void Task_USBUART(void *pvParameters)
{
    char    character = '0';
    char    c_buf[16];          // 16byte FIFO buffer
    uint8   c_ptr = 0;          // position of c_buf[]
    char    str[20];
    uint8   i;
    const   portTickType xDelay = 50 / portTICK_RATE_MS;

    USBUART_Start(0, USBUART_DWR_VDDD_OPERATION);
    // start 2kHz timer interrupt
    int_uartQueue_StartEx(int_uartQueue_isr);

    // Main Loop
 	while (1)
	{
#if 1
        // Wait until the intialization is done.
        while (USBUART_GetConfiguration() == 0);

        USBUART_IsConfigurationChanged();       // Clear CHANGE flag
        USBUART_CDC_Init();                     // Start CDC function
        for (;;)
        {
            // If the confoguration is changed, then initialize USB again.
            if (USBUART_IsConfigurationChanged())
                break;

            // Read USB port for COM data
    		//ReadUSB();
            
            // Ignore the control comands
            //(void)USBUART_IsLineChanged();
            if (uxQueueMessagesWaiting(xQueue_CHAR) > 0)
            {
                xQueueReceive(xQueue_CHAR, &character, 0);
                if (character != 0x1b)
                {
                    //c_buf[c_ptr] = character;
                    //c_ptr = (c_ptr + 1) & 0x0f;
                    putch(character);
                }
                //else    // ESC
                //{
                //    // clear the line
                //    for(i = 0; i < 16; i++)
                //       c_buf[i] = ' ';
                //}
                // copy 16 characters to sprintf buffer
                //for(i = 0; i < 16; i++)
                //    str[i] = c_buf[(c_ptr + i) & 0x0f];
                //str[16] = '\n';
                //putstr(str);
            }

            
            
            
        }
#else
        uint32 nLine = 0;           // Line number
        uint32 nChars = 0;          // Number of characters

        // Wait until the intialization is done.
        while (USBUART_GetConfiguration() == 0);

        USBUART_IsConfigurationChanged();       // Clear CHANGE flag
        USBUART_CDC_Init();                     // Start CDC function
        
        for (;;)
        {
            // If the confoguration is changed, then initialize USB again.
            if (USBUART_IsConfigurationChanged())
                break;

            // Send the number of Rx character.
            int16 ch = getch();
            putstr(" - ");
            if (ch >= 0)
            {
                nChars++;
                if (ch == '\n') 
                {
                    putdec32(nLine, 7);
                    putstr(" - ");
                    putdec32(nChars, 7);
                    putstr("\n");
                    nLine++;
                    nChars = 0;
                }
            }
            
            // Ignore the control comands
            (void)USBUART_IsLineChanged();
        }
    
    
#endif
        // sleep for 10ms
        vTaskDelay(xDelay);

    }
}

//
//	Read USB port for COM data
//
void ReadUSB (void)
{
	uint8 rx;

    rx = getch();
    //if (rx >= 0)      // always true!!
    if (rx < 0x80)
    {
        ComRxCmd[ComRxPtr++] = rx;	// save in command buffer
		if (rx == ';')				// command string terminator
		{
			//ProcessComRx();
			ComRxPtr = 0;
        }
        else if (rx == '\n' && (ComRxCmd[0] == '$') && (ComRxCmd[1] == '*'))
        {
			FactorySetup();
			ComRxPtr = 0;
        }
		else
			ComRxPtr &= sizeof(ComRxCmd) - 1;
	}
}

//
//	Factory setup commands
//
void FactorySetup (void)
{
	uint8 sendUsb = FALSE;
    uint8 i;
	
	switch (ComRxCmd [2])
	{
		//case 'b':						// bootloader mode
		//	CyBtldr_Load();				// enter USB boot loader mode
		//	break;
			
		case 'd':						// debug mode
			memcpy (UsbTxBuffer, "Debug Mode", 10);
			sendUsb = 10;
			break;
			
		case 'f':						// store frequency offset in eeprom
			CySetTemp ();				// acquire die temperature before writing eeprom
//			break;

		case '?':						// status command, reply with eeprom data
            // PSoC3 => PSoC5LP
			//memcpy (UsbTxBuffer, SERIAL_NUM, 8);		// serial number
			break;
	}

	if (sendUsb)
	{
        UsbTxBuffer [sendUsb] = '\0';   // 2017.11.4(koseki)
        putstr((char*)UsbTxBuffer);
        putch('\n');
	}
}

#if 0
//***************************************************************************
//	Task_CLCD
//***************************************************************************

const uint8 pga_gain[] = {1u, 2u, 4u, 8u, 16u, 24u, 32u, 48u};

#define GAIN_MAX    sizeof pga_gain / sizeof pga_gain[0]

void Task_CLCD(void *pvParameters)
{
    // Gain Control
    int16   gain = 2;           // init value x08
    int8    click;              // ROT +/- click count
    uint8   dahave = 36;        // average time = dash * 5ms
    uint8   update_status;      // update status line flag
    uint8   threshold;          // received from Task_Tone
    uint8   wpm;                // calculated WPM
    char    character;
    char    c_buf[16];          // 16byte FIFO buffer
    uint8   c_ptr = 0;          // position of c_buf[]
    char    str[20];
    uint8   i, hold_cntr = 0;
    const   portTickType xDelay = 50 / portTICK_RATE_MS;
    
    // Character line
    //                   "0123456789012345"
    I2C_CLCD_Position(0u, 0u);
    I2C_CLCD_PrintString("                ");
    
    for(uint i = 0; i < 16; i++)
        c_buf[i] = ' ';

    PGA_1_SetGain(pga_gain[gain]);
    update_status = 1;
    
    while(1)
    {
        if (uxQueueMessagesWaiting(xQueue_CHAR) > 0)
        {
            xQueueReceive(xQueue_CHAR, &character, 0);
            if (character != 0x1b)
            {
                c_buf[c_ptr] = character;
                c_ptr = (c_ptr + 1) & 0x0f;
            }
            else    // ESC
            {
                // clear the line
                for(i = 0; i < 16; i++)
                   c_buf[i] = ' ';
            }
            // copy 16 characters to sprintf buffer
            for(i = 0; i < 16; i++)
                str[i] = c_buf[(c_ptr + i) & 0x0f];
            str[16] = 0;
            I2C_CLCD_Position(0u, 0u);
            I2C_CLCD_PrintString(str);
        }
#if 0
        // Get click count of ROT
        if (uxQueueMessagesWaiting(xQueue_ROT) > 0)
        {
            xQueueReceive(xQueue_ROT, &click, 0);
            
            /* the target PGA gain */
            gain += click ;
            if (gain < 0)
                gain = 0;
            if ((uint16)gain > (GAIN_MAX - 1))
                gain = GAIN_MAX - 1;
            /*set PGA gain*/
            PGA_1_SetGain(pga_gain[gain]);
            update_status = 1;
        }
#endif
        // WPM is changed
        if (uxQueueMessagesWaiting(xQueue_WPM) > 0)
        {
            xQueueReceive(xQueue_WPM, &dahave, 0);
            if (dahave > 0)
                wpm = (uint8)(720 / dahave);
            else
                wpm = 0;
            update_status = 1;
        }

        // Synbol threshold is changed
        if (uxQueueMessagesWaiting(xQueue_TH) > 0)
        {
            xQueueReceive(xQueue_TH, &threshold, 0);
            update_status = 1;
        }

        if (update_status == 1)
        {
            update_status = 0;
            I2C_CLCD_Position(1u, 0u);
            if (wpm > 0)
                sprintf(str, "WPM:%02d  Th:%02d   ", wpm, threshold);
            else
                sprintf(str, "WPM:--  Th:%02d   ", threshold);   // wpm reset
            I2C_CLCD_PrintString(str);
        }
        // sleep for 100ms
        vTaskDelay(xDelay);
    }
}
#endif

// [] END OF FILE
