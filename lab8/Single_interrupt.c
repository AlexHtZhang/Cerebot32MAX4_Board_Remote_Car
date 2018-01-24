/*
** Single Interrupt Vector test
** single1.c
*/
#include <p32xxxx.h>
#include <plib.h>
#include "config.h"

int count;
void look_up_table(int no);
void Initsegs( void);

#pragma interrupt InterruptHandler ipl1 vector 0
void  InterruptHandler(void)
{
    
     count++;
     if (count==10)
     {
       count=0; 
      }
    mT2ClearIntFlag();
} // Interrupt Handler

main()
{
    // 1. init timers
    PR2 = 20000;
    T2CON = 0x8030;
    
    // 2. init interrupts
    mT2SetIntPriority( 1);
    INTEnableSystemSingleVectoredInt();         
    mT2IntEnable( 1);
    
    // 3. main loop
Initsegs();
 
 while(1)
  {   
    look_up_table(count);
   }
  


} // main

//Choose the desired 7seg display



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


