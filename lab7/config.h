

/************************************************************************/
/*																		*/
/*	config.h -- Project Configuration Declarations                      */
/*																		*/
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



/*	Seven Segment display
*/
#define trisseg1 		TRISE
#define trisseg1clr		TRISECLR
#define trisseg1set		TRISESET
#define portseg1		PORTE
#define portseg1set		PORTESET
#define portseg1clr     PORTECLR
#define seg1			7

#define trisseg4 		TRISE
#define trisseg4clr		TRISECLR
#define trisseg4set		TRISESET
#define portseg4		PORTE
#define portseg4set		PORTESET
#define portseg4clr     PORTECLR
#define seg4			4


#define trisseg5 		TRISE
#define trisseg5clr		TRISECLR
#define trisseg5set		TRISESET
#define portseg5		PORTE
#define portseg5set		PORTESET
#define portseg5clr     PORTECLR
#define seg5			5

#define trisseg6 		TRISE
#define trisseg6clr		TRISECLR
#define trisseg6set		TRISESET
#define portseg6		PORTE
#define portseg6set		PORTESET
#define portseg6clr     PORTECLR
#define seg6			6

#define trisseg7 		TRISD
#define trisseg7clr		TRISDCLR
#define trisseg7set		TRISDSET
#define portseg7		PORTD
#define portseg7set		PORTDSET
#define portseg7clr     PORTDCLR
#define seg7			4

#define trisseg3 		TRISD
#define trisseg3clr		TRISDCLR
#define trisseg3set		TRISDSET
#define portseg3		PORTD
#define portseg3set		PORTDSET
#define portseg3clr     PORTDCLR
#define seg3			5

#define trisseg2 		TRISB
#define trisseg2clr		TRISBCLR
#define trisseg2set		TRISBSET
#define portseg2		PORTB
#define portseg2set		PORTBSET
#define portseg2clr     PORTBCLR
#define seg2			15

#define triscon 		TRISB
#define trisconclr		TRISBCLR
#define trisconset		TRISBSET
#define portcon	    	PORTB
#define portconset		PORTBSET
#define portconclr      PORTBCLR
#define con 			14

#endif
