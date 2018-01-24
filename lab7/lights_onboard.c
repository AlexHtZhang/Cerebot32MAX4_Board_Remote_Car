/* 
	lights.c
	Author  : VenkataRamesh bontupalli
 * Sample program for Lab 2.
 * The program reads the onboard push button switches
 * and sets the LEDS
*/

#include <p32xxxx.h>
#include <plib.h>
#include "config.h"

int main()
{
	int i;
    //Set the onboard buttons BTN1p,BTN2p,3p,4p as inputs
    mPORTASetPinsDigitalIn(BIT_4|BIT_5|BIT_6|BIT_7);
    //Set the onboard LEDS LD0,LD1,LD2,LD3 as outputs
    TRISBCLR = (1<<LED1)|(1<<LED2)|(1<<LED3)|(1<<LED4);

    while (1) 
    {	
		
            //Read BTN0
	        int n1 = prtBtn1p & (1<<BTN1p);
            //Read BTN1
            int n2 = prtBtn2p & (1<<BTN2p);
            //Read BTN2
	        int n3 = prtBtn3p & (1<<BTN3p);
            //Read BTN3
            int n4 = prtBtn4p & (1<<BTN4p);


			//If BTN0 is pressed
 			if(n1)
            {
                //Set LED1
			   prtLed1Set = (1<<LED1);
            }
            else  //if not pressed
 			{
                //Reset LED1
				prtLed1Clr = (1<<LED1);
    		}        
            	
           //If BTN1 is pressed
 			if(n2)
            {
                //Set LED2
			   prtLed2Set = (1<<LED2);
            }
            else  //if not pressed
 			{
                //Reset LED2
				prtLed2Clr = (1<<LED2);
    		}        

           //If BTN2 is pressed
 			if(n3)
            {
                //Set LED3
			   prtLed3Set = (1<<LED3);
            }
            else  //if not pressed
 			{
                //Reset LED3
				prtLed3Clr = (1<<LED3);
    		}     

            //If BTN3 is pressed
 			if(n4)
            {
                //Set LED4
			   prtLed4Set = (1<<LED4);
            }
            else  //if not pressed
 			{
                //Reset LED4
				prtLed4Clr = (1<<LED4);
    		}     


   
	}
	return 0;
}
