#include "Filter_1.h"
#include "Filter_1_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is: Biquad
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelABiquadCoefficients Filter_1_ChannelABiquadCoefficients

/* Number of Biquad sections are: 4 */

const uint8 CYCODE Filter_1_ChannelABiquadCoefficients[Filter_1_BIQUAD_A_SIZE] = 
{
 /* Coefficients of Section 0 */
 0xE1u, 0x8Cu, 0x03u, 0x00u, /* Section(0)_A0, 0.0554735660552979 */

 0x3Fu, 0xE6u, 0xF8u, 0x00u, /* Section(0)_A1, -0.110946893692017 */

 0xE1u, 0x8Cu, 0x03u, 0x00u, /* Section(0)_A2, 0.0554735660552979 */

 0xC2u, 0x4Du, 0x76u, 0x00u, /* Section(0)_B1, -1.8484959602356 */

 0x6Cu, 0x47u, 0xC4u, 0x00u, /* Section(0)_B2, 0.933140754699707 */

 /* Coefficients of Section 1 */
 0x17u, 0x6Au, 0x00u, 0x00u, /* Section(1)_A0, 0.00647521018981934 */

 0x2Fu, 0xD4u, 0x00u, 0x00u, /* Section(1)_A1, 0.0129506587982178 */

 0x17u, 0x6Au, 0x00u, 0x00u, /* Section(1)_A2, 0.00647521018981934 */

 0x32u, 0xC5u, 0x74u, 0x00u, /* Section(1)_B1, -1.82453584671021 */

 0x7Bu, 0xAFu, 0xC4u, 0x00u, /* Section(1)_B2, 0.926789522171021 */

 /* Coefficients of Section 2 */
 0x9Fu, 0x73u, 0x09u, 0x00u, /* Section(2)_A0, 0.147681951522827 */

 0xC3u, 0x18u, 0xEDu, 0x00u, /* Section(2)_A1, -0.295363664627075 */

 0x9Fu, 0x73u, 0x09u, 0x00u, /* Section(2)_A2, 0.147681951522827 */

 0xE1u, 0x7Bu, 0x79u, 0x00u, /* Section(2)_B1, -1.89818596839905 */

 0x25u, 0xAFu, 0xC1u, 0x00u, /* Section(2)_B2, 0.973685026168823 */

 /* Coefficients of Section 3 */
 0xFFu, 0x97u, 0x02u, 0x00u, /* Section(3)_A0, 0.0405271053314209 */

 0xFDu, 0x2Fu, 0x05u, 0x00u, /* Section(3)_A1, 0.0810539722442627 */

 0xFFu, 0x97u, 0x02u, 0x00u, /* Section(3)_A2, 0.0405271053314209 */

 0x2Eu, 0x42u, 0x76u, 0x00u, /* Section(3)_B1, -1.84778928756714 */

 0x32u, 0x1Au, 0xC2u, 0x00u, /* Section(3)_B2, 0.967151165008545 */
};


/*******************************************************************************
* ChannelB filter coefficients.
* Filter Type is: Biquad
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelBBiquadCoefficients Filter_1_ChannelBBiquadCoefficients

/* Number of Biquad sections are: 4 */

const uint8 CYCODE Filter_1_ChannelBBiquadCoefficients[Filter_1_BIQUAD_B_SIZE] = 
{
 /* Coefficients of Section 0 */
 0xE1u, 0x8Cu, 0x03u, 0x00u, /* Section(0)_A0, 0.0554735660552979 */

 0x3Fu, 0xE6u, 0xF8u, 0x00u, /* Section(0)_A1, -0.110946893692017 */

 0xE1u, 0x8Cu, 0x03u, 0x00u, /* Section(0)_A2, 0.0554735660552979 */

 0xC2u, 0x4Du, 0x76u, 0x00u, /* Section(0)_B1, -1.8484959602356 */

 0x6Cu, 0x47u, 0xC4u, 0x00u, /* Section(0)_B2, 0.933140754699707 */

 /* Coefficients of Section 1 */
 0x17u, 0x6Au, 0x00u, 0x00u, /* Section(1)_A0, 0.00647521018981934 */

 0x2Fu, 0xD4u, 0x00u, 0x00u, /* Section(1)_A1, 0.0129506587982178 */

 0x17u, 0x6Au, 0x00u, 0x00u, /* Section(1)_A2, 0.00647521018981934 */

 0x32u, 0xC5u, 0x74u, 0x00u, /* Section(1)_B1, -1.82453584671021 */

 0x7Bu, 0xAFu, 0xC4u, 0x00u, /* Section(1)_B2, 0.926789522171021 */

 /* Coefficients of Section 2 */
 0x9Fu, 0x73u, 0x09u, 0x00u, /* Section(2)_A0, 0.147681951522827 */

 0xC3u, 0x18u, 0xEDu, 0x00u, /* Section(2)_A1, -0.295363664627075 */

 0x9Fu, 0x73u, 0x09u, 0x00u, /* Section(2)_A2, 0.147681951522827 */

 0xE1u, 0x7Bu, 0x79u, 0x00u, /* Section(2)_B1, -1.89818596839905 */

 0x25u, 0xAFu, 0xC1u, 0x00u, /* Section(2)_B2, 0.973685026168823 */

 /* Coefficients of Section 3 */
 0xFFu, 0x97u, 0x02u, 0x00u, /* Section(3)_A0, 0.0405271053314209 */

 0xFDu, 0x2Fu, 0x05u, 0x00u, /* Section(3)_A1, 0.0810539722442627 */

 0xFFu, 0x97u, 0x02u, 0x00u, /* Section(3)_A2, 0.0405271053314209 */

 0x2Eu, 0x42u, 0x76u, 0x00u, /* Section(3)_B1, -1.84778928756714 */

 0x32u, 0x1Au, 0xC2u, 0x00u, /* Section(3)_B2, 0.967151165008545 */
};

