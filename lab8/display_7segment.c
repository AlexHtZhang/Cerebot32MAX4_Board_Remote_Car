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
 
  int ip=0,tens=0;
  int i=0;
int b1=0,b2=0;
  Initsegs();
  while(1)
  {
//Read BTN0
  int n1 = PORTA & (1<<6);
//Read BTN1
  int n2 = PORTA & (1<<7);

    
    if(n1)
{
     b1=1;
     b2=0;
}
   if(n2)
{   b1=0;
    b2=1;
}
   if(b1)
   { ip++;
     if(ip>9)
     ip=0;
}
	
   if(b2)
   { ip--;
     if(ip<0)
     ip=9; 
    }
	for(i=0;i<=30000;i++ );
     look_up_table(ip);
     
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

