/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <device.h>

//-----------------------------------------------------------------------------
// Morse translation table
//-----------------------------------------------------------------------------
const char MorseCharTraslateTable [] =
{
	'.',
	'.', 	 
	'T',	// -
	'E',	// .
	'M',	// --
	'A',	// .-
	'N',	// -.
	'I',	// ..
	'O',	// ---
	'W',	// .--
	'K',	// -.-
	'U',	// ..-
	'G',	// --. 
	'R',	// .-.
	'D',	// -..
	'S',	// ...
	'.',	// ----
	'J',	// .---
	'Y',	// -.--
	'.',
	'Q',	// --.-
	'.',
	'X',	// -..-
	'V',	// ...-
	'.',
	'P',	// .--.
	'C',	// -.-.
	'F',	// ..-.
	'Z',	// --..
	'L',	// .-..
	'B',	// -...
	'H',	// ....
	'0',	// -----
	'1',	// .----
	'.',	// -.---
	'2',	// ..---
	'.',
	'.',	// .-.--
	'.',	// -..--
	'3',	// ...--
	'.',	// ---.-
	'A',	// .--.- 
	'~',	// -.-.- Starting signal
	'.',	// ..-.-
	'.',	// --..-
	'.',	// .-..-
	'=',	// -...-
	'4',	// ....-
	'9',	// ----.
	'.',	// .---.
	'(',	// -.--.
	'.',	// ..--.
	'.',	// --.-.
	'+',	// .-.-. End of message
	'/',	// -..-.
	'*',	// ...-. Understood
	'8',	// ---..
	'.',	// .--..
	'.',	// -.-..
	'E',	// ..-..	
	'7',	// --...
	'.',	// .-... Wait
	'6',	// -....
	'5',	// .....
	'.',	// ------
	'.',	// .-----
	'.',	// -.----
	'.',	// ..----
	'.',	// --.---
	'.',	// .-.---
	'.',	// -..---
	'.',	// ...---
	'.',	// ---.--
	'.',	// .--.--
	'.',	// -.-.--
	'.',	// ..-.--
	',',	// --..--	','
	'.',	// .-..--
	'.',	// -...--
	'.',	// ....--
	'.',	// ----.-
	'.',	// .---.-
	')',	// -.--.-
	'_',	// ..--.-
	'.',	// --.-.-
	'.',	// .-.-.-	'.'
	'.',	// -..-.-
	'.',	// ...-.- End of work
	'.',	// ---..-
	'.',	// .--..-
	'.',	// -.-..-
	'.',	// ..-..-
	'.',	// --...-
	'.',	// .-...-
	'-',	// -....-
	'.',	// .....-
	'.',	// -----.
	'.',	// .----.
	'.',	// -.---.
	'.',	// ..---.
	'.',	// --.--.
	'.',	// .-.--.
	'.',	// -..--.
	'.',	// ...--.
	'.',	// ---.-.
	'.',	// .--.-.
	';',	// -.-.-.
	'.',	// ..-.-.
	'.',	// --..-.
	'"',	// .-..-.
	'.',	// -...-.
	'.',	// ....-.
	'.',	// ----..
	'.',	// .---..
	'.',	// -.--..
	'?',	// ..--..	
	'.',	// --.-..
	'.',	// .-.-.. Paragraph
	'.',	// -..-..
	'.',	// ...-..
	':',	// ---...
	'.',	// .--...
};

//-----------------------------------------------------------------------------
// WPM table as a function of DASH average period
// PSoC5LP uses the formula WPM = (uint8)(720 / dahave)
//-----------------------------------------------------------------------------
#if 0
const uint8 WPM_Table[] =
{
	48,		// 15
	45,		// 16
	42,		// 17
	40,		// 18
	38,		// 19
	36,		// 20
	34,		// 21
	33,		// 22
	31,		// 23
	30,		// 24
	29,		// 25
	28,		// 26
	27,		// 27
	26,		// 28
	25,		// 29
	24,		// 30
	23,		// 31
	22,		// 32
	22,		// 33
	21,		// 34
	21,		// 35
	20,		// 36 = dahave, 36 * 5 = 180ms
	19,		// 37
	19,		// 38
	18,		// 39
	18,		// 40
	18,		// 41
	17,		// 42
	17,		// 43
	16,		// 44
	16,		// 45
	16,		// 46
	15,		// 47
	15,		// 48
	15,		// 49
	14,		// 50
	14,		// 51
	14,		// 52
	14,		// 53
	13,		// 54
	13,		// 55
	13,		// 56
	13,		// 57
	12,		// 58
	12,		// 59
	12,		// 60
	12,		// 61
	12,		// 62
	11,		// 63
	11,		// 64
	11,		// 65
	11,		// 66
	11,		// 67
	11,		// 68
	10,		// 69
	10,		// 70
	10,		// 71
	10,		// 72
	10,		// 73
	10,		// 74
	10,		// 75
	9,		// 76
	9,		// 77
	9,		// 78
	9,		// 79
	9,		// 80
	9,		// 81
	9,		// 82
	9,		// 83
	9,		// 84
	8,		// 85
	8,		// 86
	8,		// 87
	8,		// 88
	8,		// 89
	8,		// 90
	8,		// 91
	8,		// 92
	8,		// 93
	8,		// 94
	8,		// 95
	8,		// 96
	7,		// 97
	7,		// 98
	7,		// 99
	7,		// 100
};
#endif
/* [] END OF FILE */
