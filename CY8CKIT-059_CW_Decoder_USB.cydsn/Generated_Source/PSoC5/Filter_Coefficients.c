#include "Filter.h"
#include "Filter_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is: Biquad
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelABiquadCoefficients Filter_ChannelABiquadCoefficients

/* Number of Biquad sections are: 8 */

const uint8 CYCODE Filter_ChannelABiquadCoefficients[Filter_BIQUAD_A_SIZE] = 
{
 /* Coefficients of Section 0 */
 0xAEu, 0x56u, 0x06u, 0x00u, /* Section(0)_A0, 0.0990405082702637 */

 0xA3u, 0x52u, 0xF3u, 0x00u, /* Section(0)_A1, -0.198081254959106 */

 0xAEu, 0x56u, 0x06u, 0x00u, /* Section(0)_A2, 0.0990405082702637 */

 0xD3u, 0x4Cu, 0x75u, 0x00u, /* Section(0)_B1, -1.83281397819519 */

 0xFBu, 0xB6u, 0xC6u, 0x00u, /* Section(0)_B2, 0.895081758499146 */

 /* Coefficients of Section 1 */
 0x89u, 0xE8u, 0x16u, 0x00u, /* Section(1)_A0, 0.357942819595337 */

 0xEFu, 0x2Eu, 0xD2u, 0x00u, /* Section(1)_A1, -0.715885400772095 */

 0x89u, 0xE8u, 0x16u, 0x00u, /* Section(1)_A2, 0.357942819595337 */

 0x2Eu, 0x45u, 0x77u, 0x00u, /* Section(1)_B1, -1.86359739303589 */

 0x14u, 0x4Au, 0xC5u, 0x00u, /* Section(1)_B2, 0.917353630065918 */

 /* Coefficients of Section 2 */
 0xB3u, 0xCFu, 0x11u, 0x00u, /* Section(2)_A0, 0.278301954269409 */

 0x9Au, 0x60u, 0xDCu, 0x00u, /* Section(2)_A1, -0.556603908538818 */

 0xB3u, 0xCFu, 0x11u, 0x00u, /* Section(2)_A2, 0.278301954269409 */

 0x36u, 0x8Au, 0x79u, 0x00u, /* Section(2)_B1, -1.89906072616577 */

 0xDFu, 0x5Au, 0xC3u, 0x00u, /* Section(2)_B2, 0.94757866859436 */

 /* Coefficients of Section 3 */
 0xDEu, 0x88u, 0x00u, 0x00u, /* Section(3)_A0, 0.00835371017456055 */

 0xBBu, 0x11u, 0x01u, 0x00u, /* Section(3)_A1, 0.016707181930542 */

 0xDEu, 0x88u, 0x00u, 0x00u, /* Section(3)_A2, 0.00835371017456055 */

 0x61u, 0xFEu, 0x73u, 0x00u, /* Section(3)_B1, -1.81240105628967 */

 0x8Cu, 0x47u, 0xC7u, 0x00u, /* Section(3)_B2, 0.886258125305176 */

 /* Coefficients of Section 4 */
 0x04u, 0x9Fu, 0x00u, 0x00u, /* Section(4)_A0, 0.00970554351806641 */

 0x08u, 0x3Eu, 0x01u, 0x00u, /* Section(4)_A1, 0.0194110870361328 */

 0x04u, 0x9Fu, 0x00u, 0x00u, /* Section(4)_A2, 0.00970554351806641 */

 0xC2u, 0xC7u, 0x73u, 0x00u, /* Section(4)_B1, -1.8090672492981 */

 0x07u, 0xA8u, 0xC6u, 0x00u, /* Section(4)_B2, 0.895994424819946 */

 /* Coefficients of Section 5 */
 0xA8u, 0xA3u, 0x00u, 0x00u, /* Section(5)_A0, 0.00998878479003906 */

 0x4Fu, 0x47u, 0x01u, 0x00u, /* Section(5)_A1, 0.019977331161499 */

 0xA8u, 0xA3u, 0x00u, 0x00u, /* Section(5)_A2, 0.00998878479003906 */

 0xBEu, 0xE8u, 0x74u, 0x00u, /* Section(5)_B1, -1.82670545578003 */

 0x55u, 0xBDu, 0xC4u, 0x00u, /* Section(5)_B2, 0.925944089889526 */

 /* Coefficients of Section 6 */
 0x28u, 0xDFu, 0x0Eu, 0x00u, /* Section(6)_A0, 0.232370376586914 */

 0xB0u, 0x41u, 0xE2u, 0x00u, /* Section(6)_A1, -0.464740753173828 */

 0x28u, 0xDFu, 0x0Eu, 0x00u, /* Section(6)_A2, 0.232370376586914 */

 0xB8u, 0xDFu, 0x7Bu, 0x00u, /* Section(6)_B1, -1.9355297088623 */

 0xD6u, 0x27u, 0xC1u, 0x00u, /* Section(6)_B2, 0.981943607330322 */

 /* Coefficients of Section 7 */
 0x90u, 0xBAu, 0x03u, 0x00u, /* Section(7)_A0, 0.0582618713378906 */

 0x20u, 0x75u, 0x07u, 0x00u, /* Section(7)_A1, 0.116523742675781 */

 0x90u, 0xBAu, 0x03u, 0x00u, /* Section(7)_A2, 0.0582618713378906 */

 0x12u, 0x57u, 0x77u, 0x00u, /* Section(7)_B1, -1.86468935012817 */

 0xC5u, 0xBEu, 0xC1u, 0x00u, /* Section(7)_B2, 0.972731351852417 */
};

