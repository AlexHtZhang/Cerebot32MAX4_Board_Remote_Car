/************************************************************************/
/*																		*/
/*	config.h -- Project Configuration Declarations                      */
/*																		*/
/************************************************************************/
/*	Author: Julian D John									*/
/*	                										*/
/************************************************************************/
/*  Module Description: 												*/
/*																		*/
/*	This header contains declarations used to configure the project     */
/*  based on the target platform.                                       */
/*																		*/
/************************************************************************/
/************************************************************************/

#if !defined(_CONFIG_INC)
#define _CONFIG_INC

/* ------------------------------------------------------------ */
/*					     Pin Definitions   		    			*/
/* ------------------------------------------------------------ */

/*	Onboard LEDs
*/
#define	trisLed1			TRISB
#define	trisLed1Set			TRISBSET
#define	trisLed1Clr			TRISBCLR
#define	prtLed1				PORTB
#define	prtLed1Set			PORTBSET
#define	prtLed1Clr			PORTBCLR
#define	prtLed1Inv			PORTBINV
#define	LED1				10

#define	trisLed2			TRISB
#define	trisLed2Set			TRISBSET
#define	trisLed2Clr			TRISBCLR
#define	prtLed2				PORTB
#define	prtLed2Set			PORTBSET
#define	prtLed2Clr			PORTBCLR
#define	prtLed2Inv			PORTBINV
#define	LED2				11

#define	trisLed3			TRISB
#define	trisLed3Set			TRISBSET
#define	trisLed3Clr			TRISBCLR
#define	prtLed3				PORTB
#define	prtLed3Set			PORTBSET
#define	prtLed3Clr			PORTBCLR
#define	prtLed3Inv			PORTBINV
#define	LED3				12

#define	trisLed4			TRISB
#define	trisLed4Set			TRISBSET
#define	trisLed4Clr			TRISBCLR
#define	prtLed4				PORTB
#define	prtLed4Set			PORTBSET
#define	prtLed4Clr			PORTBCLR
#define	prtLed4Inv			PORTBINV
#define	LED4				13

/*	Onboard Buttons
*/

#define	trisBtn1			TRISA
#define	trisBtn1Set			TRISASET
#define	trisBtn1Clr			TRISACLR
#define	prtBtn1				PORTA
#define	prtBtn1Set			PORTASET
#define	prtBtn1Clr			PORTACLR
#define	BTN1				6

#define	trisBtn2			TRISA
#define	trisBtn2Set			TRISASET
#define	trisBtn2Clr			TRISACLR
#define	prtBtn2				PORTA
#define	prtBtn2Set			PORTASET
#define	prtBtn2Clr			PORTACLR
#define	BTN2				7

/*Header JA PushButton PMOD*/

#define	trisBtn1p			TRISE
#define	trisBtn1pSet		TRISESET
#define	trisBtn1pClr		TRISECLR
#define	prtBtn1p			PORTE
#define	prtBtn1pSet			PORTESET
#define	prtBtn1pClr			PORTECLR
#define	BTN1p				4

#define	trisBtn2p			TRISE
#define	trisBtn2pSet		TRISESET
#define	trisBtn2pClr		TRISECLR
#define	prtBtn2p			PORTE
#define	prtBtn2pSet			PORTESET
#define	prtBtn2pClr			PORTECLR
#define	BTN2p				5

#define	trisBtn3p			TRISE
#define	trisBtn3pSet		TRISESET
#define	trisBtn3pClr		TRISECLR
#define	prtBtn3p			PORTE
#define	prtBtn3pSet			PORTESET
#define	prtBtn3pClr			PORTECLR
#define	BTN3p				6

#define	trisBtn4p			TRISE
#define	trisBtn4pSet		TRISESET
#define	trisBtn4pClr		TRISECLR
#define	prtBtn4p			PORTE
#define	prtBtn4pSet			PORTESET
#define	prtBtn4pClr			PORTECLR
#define	BTN4p				7




/* ------------------------------------------------------------ */
/*					Miscellaneous Declarations					*/
/* ------------------------------------------------------------ */



/* ------------------------------------------------------------ */
/*					General Type Declarations					*/
/* ------------------------------------------------------------ */



/* ------------------------------------------------------------ */
/*					Object Class Declarations					*/
/* ------------------------------------------------------------ */



/* ------------------------------------------------------------ */
/*					Variable Declarations						*/
/* ------------------------------------------------------------ */



/* ------------------------------------------------------------ */
/*					Procedure Declarations						*/
/* ------------------------------------------------------------ */



/* ------------------------------------------------------------ */

#endif
