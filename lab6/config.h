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

/*Header JK PushButton PMOD*/

#define	trisBtn1p			TRISA
#define	trisBtn1pSet		TRISASET
#define	trisBtn1pClr		TRISACLR
#define	prtBtn1p			PORTA
#define	prtBtn1pSet			PORTASET
#define	prtBtn1pClr			PORTACLR
#define	BTN1p				9

#define	trisBtn2p			TRISA
#define	trisBtn2pSet		TRISASET
#define	trisBtn2pClr		TRISACLR
#define	prtBtn2p			PORTA
#define	prtBtn2pSet			PORTASET
#define	prtBtn2pClr			PORTACLR
#define	BTN2p				10

#define	trisBtn3p			TRISD
#define	trisBtn3pSet		TRISDSET
#define	trisBtn3pClr		TRISDCLR
#define	prtBtn3p			PORTD
#define	prtBtn3pSet			PORTDSET
#define	prtBtn3pClr			PORTDCLR
#define	BTN3p				12

#define	trisBtn4p			TRISC
#define	trisBtn4pSet		TRISCSET
#define	trisBtn4pClr		TRISCCLR
#define	prtBtn4p			PORTC
#define	prtBtn4pSet			PORTCSET
#define	prtBtn4pClr			PORTCCLR
#define	BTN4p				4

/*
PMOD LEDS

*/
#define trisLd0				TRISE
#define	trisLd0Set			TRISESET
#define	trisLd0Clr			TRISECLR
#define	prtLd0				PORTE
#define	prtLd0Set			PORTESET
#define	prtLd0Clr			PORTECLR
#define	LD0				    0

#define trisLd1				TRISE
#define	trisLd1Set			TRISESET
#define	trisLd1Clr			TRISECLR
#define	prtLd1				PORTE
#define	prtLd1Set			PORTESET
#define	prtLd1Clr			PORTECLR
#define	LD1				    1

#define trisLd2				TRISE
#define	trisLd2Set			TRISESET
#define	trisLd2Clr			TRISECLR
#define	prtLd2				PORTE
#define	prtLd2Set			PORTESET
#define	prtLd2Clr			PORTECLR
#define	LD2			     	2

#define trisLd3				TRISE
#define	trisLd3Set			TRISESET
#define	trisLd3Clr			TRISECLR
#define	prtLd3				PORTE
#define	prtLd3Set			PORTESET
#define	prtLd3Clr			PORTECLR
#define	LD3				    3

#define trisLd4				TRISE
#define	trisLd4Set			TRISESET
#define	trisLd4Clr			TRISECLR
#define	prtLd4				PORTE
#define	prtLd4Set			PORTESET
#define	prtLd4Clr			PORTECLR
#define	LD4				    4

#define trisLd5				TRISE
#define	trisLd5Set			TRISESET
#define	trisLd5Clr			TRISECLR
#define	prtLd5				PORTE
#define	prtLd5Set			PORTESET
#define	prtLd5Clr			PORTECLR
#define	LD5  				5

#define trisLd6				TRISE
#define	trisLd6Set			TRISESET
#define	trisLd6Clr			TRISECLR
#define	prtLd6				PORTE
#define	prtLd6Set			PORTESET
#define	prtLd6Clr			PORTECLR
#define	LD6 				6


#define trisLd7				TRISE
#define	trisLd7Set			TRISESET
#define	trisLd7Clr			TRISECLR
#define	prtLd7				PORTE
#define	prtLd7Set			PORTESET
#define	prtLd7Clr			PORTECLR
#define	LD7 				7




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
