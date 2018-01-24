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
    
   jal     mPORTBSetDigitalIn
   nop
endless:
   
   jal     mPORTBSet
   nop

   jal		mPORTBClear
   nop


    
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


.ent mPORTBSetDigitalIn 
mPORTBSetDigitalIn:
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

.end mPORTBSetDigitalIn


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
    addi s2,zero,1
    addi s1,zero,30000
  L1:
    addi s2,s2,1
    bne s1,s2,L1
    nop
    addi s1,zero,0

    la       s0, prtLed2Set
    sw       t2, 0( s0)
    addi s2,zero,1
    addi s1,zero,30000
  L2:
    addi s2,s2,1
    bne s1,s2,L2
    nop
    addi s1,zero,0
 
    la       s0, prtLed3Set
    sw       t3, 0( s0)
    addi s2,zero,1
    addi s1,zero,30000
  L3:
    addi s2,s2,1
    bne s1,s2,L3
    nop
    addi s1,zero,0

    la       s0, prtLed4Set
    sw       t4, 0( s0)
    addi s2,zero,1
    addi s1,zero,30000
  L4:
    addi s2,s2,1
    bne s1,s2,L4
    nop
    addi s1,zero,0

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
    addi s2,zero,1
    addi s1,zero,30000
  L5:
    addi s2,s2,1
    bne s1,s2,L5
    nop
    addi s1,zero,0

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