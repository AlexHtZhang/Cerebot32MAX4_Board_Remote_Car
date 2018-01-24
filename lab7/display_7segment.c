/************************************************************************/
/*										                        		*/
/*	main.c	-- Seven Segment Demo									                */
/*											                        	*/
/*											                        	*/
/************************************************************************/
/*	Author: 	VenkataRamesh bontupalli/Chong Chen   					            	*/
/*	Copyright 2012              					            		*/
/************************************************************************/
/*  Module Description: 						                		*/
/*											                        	*/
/*	This module implements a simple application that demonstrates how	*/
/*	to debounce the seven segment display when the switches are pressed */                                               	
/*	                            										*/
/*																		*/
/*	Functionality:														*/
/*																		*/
/*	The on-board switchess and the Pmodsevensegment are updated 		*/
/*	as the switches are pressed.                                    	*/
/*                                                                      */
/*	Required Hardware:													*/
/*		1. Cerebot 32MX4												*/
/*		2. PmodSSD (plugged into header JA and JB)								*/
/*                                                                      */
/************************************************************************/

/* ------------------------------------------------------------ */
/*				Include File Definitions	            	    */
/* ------------------------------------------------------------ */

/* lights.c
 *
 *  Connect the switches to the LEDs
*/
#include <p32xxxx.h>
#include <plib.h>
#include "config.h"

void Initsegs( void);
void look_up_table( int no);

int count,flag=0;


int main()
{
  mPORTASetPinsDigitalIn(BIT_6|BIT_7);
 TRISBCLR = (1<<LED1)|(1<<LED2)|(1<<LED3)|(1<<LED4);



  int ip=0,tens=0;
  int j=0;
  Initsegs();
  while(1)
  {
//Read BTN0
  int n1 = prtBtn1 & (1<<BTN1);
//Read BTN1
  int n2 = prtBtn2 & (1<<BTN2);

    look_up_table(ip);
    if(n1)
    {
    prtLed1Set = (1<<LED1);
    for(j=0;j<=10000;j++);
    ip++;
    if(ip>9)
    ip=0;
				}
    else  //if not pressed
 			{
                //Reset LED1
				prtLed1Clr = (1<<LED1);
    		}  
      
   if(n2)
    {
    prtLed2Set = (1<<LED2);
    for(j=0;j<=10000;j++);
    ip--;
    if(ip<0)
    ip=9;
				}
    else  //if not pressed
 			{
                //Reset LED2
				prtLed2Clr = (1<<LED2);
    		}        



  }
}

void Initsegs( void)
{
trisseg1clr = ( 1<< seg1);
trisseg2clr = ( 1<< seg2);
trisseg3clr = ( 1<< seg3);
trisseg4clr = ( 1<< seg4);
trisseg5clr = ( 1<< seg5);
trisseg6clr = ( 1<< seg6);
trisseg7clr = ( 1<< seg7);

portseg1clr = ( 1 << seg1);
portseg2clr = ( 1 << seg2);
portseg3clr = ( 1 << seg3);
portseg4clr = ( 1 << seg4);
portseg5clr = ( 1 << seg5);
portseg6clr = ( 1 << seg6);
portseg7clr = ( 1 << seg7);

//Choose the desired 7seg display

trisconclr =  ( 1 << con);
portconset =   ( 1 << con);
}

void look_up_table(int no)
{
if(no==1)
{
portseg1clr = ( 1 << seg1);portseg2set = ( 1 << seg2);portseg3set = ( 1 << seg3);portseg4clr = ( 1 << seg4);portseg5clr = ( 1 << seg5);portseg6clr = ( 1 << seg6);portseg7clr = ( 1 << seg7);
}
else
if(no==2)
{portseg1set = ( 1 << seg1);portseg2set = ( 1 << seg2);portseg3clr = ( 1 << seg3);portseg4set = ( 1 << seg4);portseg5set = ( 1 << seg5);portseg6clr = ( 1 << seg6);portseg7set = ( 1 << seg7);}
else
if(no==3)
{portseg1set = ( 1 << seg1);portseg2set = ( 1 << seg2);portseg3set = ( 1 << seg3);portseg4set = ( 1 << seg4);portseg5clr = ( 1 << seg5);portseg6clr = ( 1 << seg6);portseg7set = ( 1 << seg7);}
else
if(no==4)
{portseg1clr = ( 1 << seg1);portseg2set = ( 1 << seg2);portseg3set = ( 1 << seg3);portseg4clr = ( 1 << seg4);portseg5clr = ( 1 << seg5);portseg6set = ( 1 << seg6);portseg7set = ( 1 << seg7);}
else
if(no==5)
{ portseg1set = ( 1 << seg1);portseg2clr = ( 1 << seg2);portseg3set = ( 1 << seg3);portseg4set = ( 1 << seg4);portseg5clr = ( 1 << seg5);portseg6set = ( 1 << seg6);portseg7set = ( 1 << seg7);}
else
if(no==6)
{ portseg1set = ( 1 << seg1);portseg2clr = ( 1 << seg2);portseg3set = ( 1 << seg3);portseg4set = ( 1 << seg4);portseg5set = ( 1 << seg5);portseg6set = ( 1 << seg6);portseg7set = ( 1 << seg7);}
else
if(no==7)
{ portseg1set = ( 1 << seg1);portseg2set = ( 1 << seg2);portseg3set = ( 1 << seg3);portseg4clr = ( 1 << seg4);portseg5clr = ( 1 << seg5);portseg6clr = ( 1 << seg6);portseg7clr = ( 1 << seg7);}
else
if(no==8)
{ portseg1set = ( 1 << seg1);portseg2set = ( 1 << seg2);portseg3set = ( 1 << seg3);portseg4set = ( 1 << seg4);portseg5set = ( 1 << seg5);portseg6set = ( 1 << seg6);portseg7set = ( 1 << seg7);}
else
if(no==9)
{ portseg1set = ( 1 << seg1);portseg2set = ( 1 << seg2);portseg3set = ( 1 << seg3);portseg4set = ( 1 << seg4);portseg5clr = ( 1 << seg5);portseg6set = ( 1 << seg6);portseg7set = ( 1 << seg7);}
else
{ portseg1set = ( 1 << seg1);portseg2set = ( 1 << seg2);portseg3set = ( 1 << seg3);portseg4set = ( 1 << seg4);portseg5set = ( 1 << seg5);portseg6set = ( 1 << seg6);portseg7clr = ( 1 << seg7);}
}

