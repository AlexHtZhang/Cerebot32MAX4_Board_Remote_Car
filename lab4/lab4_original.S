/*********************************************************************
 *
 *                  Example Assembly Project
 *
 *********************************************************************
 * FileName:        ports_control.S
 *
 * Processor:       PIC32MX
 * 
 * Assembler/Compiler/Linker:  MPLAB C32
 *
 *********************************************************************
 *
 * Description:
 * This project demonstrates how to build projects with only
 * assembly language source files.
 * This example uses "S" extension so that the 'C' pre-processor
 * can be used.
 *
 * This example provides simple assembly application. It uses
 * standard C Startup code provided by the C32 compiler.
 *
 *  This code was modified from a version
 *  "ports_control_assembly_example" found in a collection of code
 *  examples on <a href="http://www.microchip.com">microchip.com</a>.
 *
 ********************************************************************/
#include <p32xxxx.h>
#include "config.h"



	/* define all global symbols here */
	.global main

    /* define which section (for example "text")
     * does this portion of code resides in. Typically,
     * all your code will reside in .text section as
     * shown below.
     */
	.text

    /* This is important for an assembly programmer. This
     * directive tells the assembler that don't optimize
     * the order of the instructions as well as don't insert
     * 'nop' instructions after jumps and branches.
    */
	.set noreorder

/*********************************************************************
 * main()
 * This is where the PIC32 start-up code will jump to after initial
 * set-up.
 ********************************************************************/

.ent main /* directive that marks symbol 'main' as function in ELF
           * output
           */

main:

    /* Set output pins (LEDs) */
   jal     mPORTBSetDigitalOut
   nop
   /* Set input pins (Switches) */
    
   jal     mPORTASetDigitalIn
   nop
endless:
/*Read PORTA for checking BTN1*/
   la       s1,PORTA
   lw       a1,0( s1)
   
   
   jal     CheckandSet
   nop
/*Read PORTA for checking BTN2*/   
   la       s1,PORTA
   lw       a1,0( s1)
   
   jal     CheckandSet
   nop
/*   jal     mPORTBSet
   nop

   jal		mPORTBClear
   nop*/

    
    j endless
    nop
    

.end main /* directive that marks end of 'main' function and registers
           * size in ELF output
           */
.ent mPORTBSetDigitalOut 
mPORTBSetDigitalOut:
	/* function prologue - save registers used in this function 
     * on stack and adjust stack-pointer
     */
	addiu	 sp,  sp, -24
	sw		 a0, 0( sp)
    sw		 t1, 4( sp)
    sw		 t2, 8( sp)
    sw		 t3, 12( sp)
    sw		 t4, 16( sp)
    sw		 s0, 20( sp)

    ori      a0, zero,1  
    sll      t1, a0,LED1
    sll      t2, a0,LED2
    sll      t3, a0,LED3
    sll      t4, a0,LED4

	la       s0, trisLed1Clr
    sw       t1, 0( s0)

    la       s0, trisLed2Clr
    sw       t2, 0( s0)
 
    la       s0, trisLed3Clr
    sw       t3, 0( s0)

    la       s0, trisLed4Clr
    sw       t4, 0( s0)

	/* function epilogue - restore registers used in this function
     * from stack and adjust stack-pointer
     */
	lw		 s0, 20( sp)
    lw		 t4, 16( sp)
    lw		 t3, 12( sp)
    lw		 t2, 8( sp)
    lw		 t1, 4( sp)
    lw		 a0, 0( sp)

	addiu	 sp,  sp, 24

	/* return to caller */
	jr		 ra
	nop

.end mPORTBSetDigitalOut


.ent mPORTASetDigitalIn 
mPORTASetDigitalIn:
	addiu	 sp,  sp, -16
	sw		 s0, 0( sp)
    sw       a0, 4( sp)
    sw       t5, 8( sp)
    sw       t6, 12( sp)

    addi     a0, zero,1
    sll      t5, a0,BTN1
    sll      t6, a0,BTN2

    la        s0,trisBtn1Set
    sw        t5,0( s0)

    
    la        s0,trisBtn2Set
    sw        t6,0( s0)

    lw       t6,12( sp)
    lw       t5,8( sp)
    lw       a0,4( sp)
    lw       s0,0( sp)
    addiu    sp,  sp,16

    jr		 ra
	nop

.end mPORTASetDigitalIn


.ent mPORTBSet 
mPORTBSet:
	addiu	 sp,  sp, -24
	sw		 a0, 0( sp)
    sw		 t1, 4( sp)
    sw		 t2, 8( sp)
    sw		 t3, 12( sp)
    sw		 t4, 16( sp)
    sw		 s0, 20( sp)
 
    ori      a0, zero,1  
    sll      t1, a0,LED1
    sll      t2, a0,LED2
    sll      t3, a0,LED3
    sll      t4, a0,LED4

	la       s0, prtLed1Set
    sw       t1, 0( s0)

    la       s0, prtLed2Set
    sw       t2, 0( s0)
 
    la       s0, prtLed3Set
    sw       t3, 0( s0)

    la       s0, prtLed4Set
    sw       t4, 0( s0)

	lw		 s0, 20( sp)
    lw		 t4, 16( sp)
    lw		 t3, 12( sp)
    lw		 t2, 8( sp)
    lw		 t1, 4( sp)
    lw		 a0, 0( sp)

	addiu	 sp,  sp, 24


jr		 ra
nop

.end mPORTBSet


.ent mPORTBClear
mPORTBClear:

addiu	 sp,  sp, -24
	sw		 a0, 0( sp)
    sw		 t1, 4( sp)
    sw		 t2, 8( sp)
    sw		 t3, 12( sp)
    sw		 t4, 16( sp)
    sw		 s0, 20( sp)

    ori      a0, zero,1  
    sll      t1, a0,LED1
    sll      t2, a0,LED2
    sll      t3, a0,LED3
    sll      t4, a0,LED4

	la       s0, PORTBCLR
    sw       t1, 0( s0)

    la       s0, prtLed2Clr
    sw       t2, 0( s0)
 
    la       s0, prtLed3Clr
    sw       t3, 0( s0)

    la       s0, prtLed4Clr
    sw       t4, 0( s0)

	lw		 s0, 20( sp)
    lw		 t4, 16( sp)
    lw		 t3, 12( sp)
    lw		 t2, 8( sp)
    lw		 t1, 4( sp)
    lw		 a0, 0( sp)

	addiu	 sp,  sp, 24

jr		 ra
nop

.end mPORTBClear


.ent CheckandSet 
CheckandSet:

/*Write your function here */
addi a0,zero,1
    sll t5,a0,BTN1
    sll t6,a0,BTN2
    sll t1,a0,LED1
    sll t2,a0,LED2
    sll t3,a0,LED3
    sll t4,a0,LED4
    
    and a2,a1,t5
    bne a2,zero,TurnLED1and3
    nop
    j Turnoff
     
    
    and a2,a1,t6
    bne a2,zero,TurnLED2and4
    nop
    j Turnoff
    
 


TurnLED1and3:    
    la       s0, prtLed1Set
    sw       t1, 0( s0)
    la       s0, prtLed3Set
    sw       t3, 0( s0)
    nop
    j Turnoff
   

TurnLED2and4:
    la       s0, prtLed2Set
    sw       t2, 0( s0)
    la       s0, prtLed4Set
    sw       t4, 0( s0)
    nop
    j Turnoff
    

Turnoff:
    la       s0, prtLed1Clr
    sw       t1, 0( s0)

    la       s0, prtLed2Clr
    sw       t2, 0( s0)
 
    la       s0, prtLed3Clr
    sw       t3, 0( s0)

    la       s0, prtLed4Clr
    sw       t4, 0( s0)
    nop
    j end    
end:


jr  ra
nop

.end CheckandSet