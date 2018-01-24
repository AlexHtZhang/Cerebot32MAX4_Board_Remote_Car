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
   
   jal     mPORTESetDigitalOut
   nop
   /* Set input pins (Switches) */
    
   jal     mPORTBSetDigitalIn
   nop
   
   jal     mPORTASetDigitalIn
   nop
 
   jal		mPORTBClear
   nop
   
   jal      mPORTEClear
   nop
   
   jal     mPORTESet
   nop
endless:
/*Read PORT for checking PMOD BTN*/

   jal     CheckandSet
   nop
    
    j endless
    nop
    

.end main /* directive that marks end of 'main' function and registers
           * size in ELF output
           */

.ent mPORTASetDigitalIn 
mPORTASetDigitalIn:
	addiu	sp, sp, -16
	sw		s0, 0(sp)
    sw      a0, 4(sp)
    sw      t5, 8(sp)
    sw      t6, 12(sp)

    addi    a0,zero,1
    sll     t5,a0,BTN1
    sll     t6,a0,BTN2

    la       s0,trisBtn1Set
    sw       t5,0(s0)

    
    la       s0,trisBtn2Set
    sw       t6,0(s0)

    lw      t6,12(sp)
    lw      t5,8(sp)
    lw      a0,4(sp)
    lw      s0,0(sp)
    addiu   sp, sp,16

    jr		ra
	nop

.end mPORTASetDigitalIn
		   
.ent mPORTESetDigitalOut 
mPORTESetDigitalOut:
	/* function prologue - save registers used in this function 
     * on stack and adjust stack-pointer
     */
	addiu	sp, sp, -40
	sw		a0, 0(sp)
    sw      t0, 4(sp)
    sw		t1, 8(sp)
    sw		t2, 12(sp)
    sw		t3, 16(sp)
    sw		t4, 20(sp)
    sw      t5, 24(sp)
    sw      t6, 28(sp)
    sw      t7, 32(sp)
    sw		s0, 36(sp)

    ori     a0,zero,1
    sll     t0,a0,LD0  
    sll     t1,a0,LD1
    sll     t2,a0,LD2
    sll     t3,a0,LD3
    sll     t4,a0,LD4
	sll     t5,a0,LD5
    sll     t6,a0,LD6
    sll     t7,a0,LD7
    
	la      s0, trisLd0Clr
    sw      t0, 0(s0)

    la      s0, trisLd1Clr
    sw      t1, 0(s0)
 
    la      s0, trisLd2Clr
    sw      t2, 0(s0)

    la      s0, trisLd3Clr
    sw      t3, 0(s0)
	
	la      s0, trisLd4Clr
    sw      t4, 0(s0)

    la      s0, trisLd5Clr
    sw      t5, 0(s0)
 
    la      s0, trisLd6Clr
    sw      t6, 0(s0)

    la      s0, trisLd7Clr
    sw      t7, 0(s0)

	/* function epilogue - restore registers used in this function
     * from stack and adjust stack-pointer
     */
	lw		s0, 36(sp)
    lw		t7, 32(sp)
    lw		t6, 28(sp)
    lw		t5, 24(sp)
    lw		t4, 20(sp)
    lw		t3, 16(sp)
    lw		t2, 12(sp)
    lw		t1, 8(sp)
    lw		t0, 4(sp)
    lw		a0, 0(sp)
	addiu	sp, sp, 40

	/* return to caller */
	jr		ra
	nop

.end mPORTESetDigitalOut

		   
.ent mPORTEClear 
mPORTEClear:
	/* function prologue - save registers used in this function 
     * on stack and adjust stack-pointer
     */
	addiu	sp, sp, -40
	sw		a0, 0(sp)
    sw      t0, 4(sp)
    sw		t1, 8(sp)
    sw		t2, 12(sp)
    sw		t3, 16(sp)
    sw		t4, 20(sp)
    sw      t5, 24(sp)
    sw      t6, 28(sp)
    sw      t7, 32(sp)
    sw		s0, 36(sp)

    ori     a0,zero,1
    sll     t0,a0,LD0  
    sll     t1,a0,LD1
    sll     t2,a0,LD2
    sll     t3,a0,LD3
    sll     t4,a0,LD4
	sll     t5,a0,LD5
    sll     t6,a0,LD6
    sll     t7,a0,LD7
    
	la      s0, prtLd0Clr
    sw      t0, 0(s0)

    la      s0, prtLd1Clr
    sw      t1, 0(s0)
 
    la      s0, prtLd2Clr
    sw      t2, 0(s0)

    la      s0, prtLd3Clr
    sw      t3, 0(s0)
	
	la      s0, prtLd4Clr
    sw      t4, 0(s0)

    la      s0, prtLd5Clr
    sw      t5, 0(s0)
 
    la      s0, prtLd6Clr
    sw      t6, 0(s0)

    la      s0, prtLd7Clr
    sw      t7, 0(s0)

	/* function epilogue - restore registers used in this function
     * from stack and adjust stack-pointer
     */
	lw		s0, 36(sp)
    lw		t7, 32(sp)
    lw		t6, 28(sp)
    lw		t5, 24(sp)
    lw		t4, 20(sp)
    lw		t3, 16(sp)
    lw		t2, 12(sp)
    lw		t1, 8(sp)
    lw		t0, 4(sp)
    lw		a0, 0(sp)
	addiu	sp, sp, 40

	/* return to caller */
	jr		ra
	nop

.end mPORTEClear

.ent mPORTESet 
mPORTESet:
	/* function prologue - save registers used in this function 
     * on stack and adjust stack-pointer
     */
	addiu	sp, sp, -40
	sw		a0, 0(sp)
    sw      t0, 4(sp)
    sw		t1, 8(sp)
    sw		t2, 12(sp)
    sw		t3, 16(sp)
    sw		t4, 20(sp)
    sw      t5, 24(sp)
    sw      t6, 28(sp)
    sw      t7, 32(sp)
    sw		s0, 36(sp)

    ori     a0,zero,1
    sll     t0,a0,LD0  
    sll     t1,a0,LD1
    sll     t2,a0,LD2
    sll     t3,a0,LD3
    sll     t4,a0,LD4
	sll     t5,a0,LD5
    sll     t6,a0,LD6
    sll     t7,a0,LD7
    
	la      s0, prtLd0Set
    sw      t0, 0(s0)

    la      s0, prtLd1Set
    sw      t1, 0(s0)
 
    la      s0, prtLd2Set
    sw      t2, 0(s0)

    la      s0, prtLd3Set
    sw      t3, 0(s0)
	
	la      s0, prtLd4Set
    sw      t4, 0(s0)

    la      s0, prtLd5Set
    sw      t5, 0(s0)
 
    la      s0, prtLd6Set
    sw      t6, 0(s0)

    la      s0, prtLd7Set
    sw      t7, 0(s0)

	/* function epilogue - restore registers used in this function
     * from stack and adjust stack-pointer
     */
	lw		s0, 36(sp)
    lw		t7, 32(sp)
    lw		t6, 28(sp)
    lw		t5, 24(sp)
    lw		t4, 20(sp)
    lw		t3, 16(sp)
    lw		t2, 12(sp)
    lw		t1, 8(sp)
    lw		t0, 4(sp)
    lw		a0, 0(sp)
	addiu	sp, sp, 40

	/* return to caller */
	jr		ra
	nop

.end mPORTESet

.ent mPORTBSetDigitalOut 
mPORTBSetDigitalOut:
	/* function prologue - save registers used in this function 
     * on stack and adjust stack-pointer
     */
	addiu	sp, sp, -24
	sw		a0, 0(sp)
    sw		t1, 4(sp)
    sw		t2, 8(sp)
    sw		t3, 12(sp)
    sw		t4, 16(sp)
    sw		s0, 20(sp)

    ori     a0,zero,1  
    sll     t1,a0,LED1
    sll     t2,a0,LED2
    sll     t3,a0,LED3
    sll     t4,a0,LED4

	la      s0, trisLed1Clr
    sw      t1, 0(s0)

    la      s0, trisLed2Clr
    sw      t2, 0(s0)
 
    la      s0, trisLed3Clr
    sw      t3, 0(s0)

    la      s0, trisLed4Clr
    sw      t4, 0(s0)

	/* function epilogue - restore registers used in this function
     * from stack and adjust stack-pointer
     */
	lw		s0, 20(sp)
    lw		t4, 16(sp)
    lw		t3, 12(sp)
    lw		t2, 8(sp)
    lw		t1, 4(sp)
    lw		a0, 0(sp)

	addiu	sp, sp, 24

	/* return to caller */
	jr		ra
	nop

.end mPORTBSetDigitalOut


.ent mPORTBSetDigitalIn 
mPORTBSetDigitalIn:
	addiu	sp, sp, -24
	sw		s0, 0(sp)
    sw      a0, 4(sp)
    sw      t5, 8(sp)
    sw      t6, 12(sp)
    sw      t7, 16(sp)
    sw      t8, 20(sp)

    addi    a0,zero,1
    sll     t5,a0,BTN1p
    sll     t6,a0,BTN2p
    sll     t7,a0,BTN3p
    sll     t8,a0,BTN4p
    

    la       s0,trisBtn1pSet
    sw       t5,0(s0)

    
    la       s0,trisBtn2pSet
    sw       t6,0(s0)

    la       s0,trisBtn3pSet
    sw       t7,0(s0)

    
    la       s0,trisBtn4pSet
    sw       t8,0(s0)


    lw      t8,20(sp)
    lw      t7,16(sp)
    lw      t6,12(sp)
    lw      t5,8(sp)
    lw      a0,4(sp)
    lw      s0,0(sp)
    addiu   sp, sp,24

    jr		ra
	nop

.end mPORTBSetDigitalIn


.ent mPORTBSet 
mPORTBSet:
	addiu	sp, sp, -24
	sw		a0, 0(sp)
    sw		t1, 4(sp)
    sw		t2, 8(sp)
    sw		t3, 12(sp)
    sw		t4, 16(sp)
    sw		s0, 20(sp)
 
    ori     a0,zero,1  
    sll     t1,a0,LED1
    sll     t2,a0,LED2
    sll     t3,a0,LED3
    sll     t4,a0,LED4

	la      s0, prtLed1Set
    sw      t1, 0(s0)

    la      s0, prtLed2Set
    sw      t2, 0(s0)
 
    la      s0, prtLed3Set
    sw      t3, 0(s0)

    la      s0, prtLed4Set
    sw      t4, 0(s0)

	lw		s0, 20(sp)
    lw		t4, 16(sp)
    lw		t3, 12(sp)
    lw		t2, 8(sp)
    lw		t1, 4(sp)
    lw		a0, 0(sp)

	addiu	sp, sp, 24


jr		ra
nop

.end mPORTBSet


.ent mPORTBClear
mPORTBClear:

addiu	sp, sp, -24
	sw		a0, 0(sp)
    sw		t1, 4(sp)
    sw		t2, 8(sp)
    sw		t3, 12(sp)
    sw		t4, 16(sp)
    sw		s0, 20(sp)

    ori     a0,zero,1  
    sll     t1,a0,LED1
    sll     t2,a0,LED2
    sll     t3,a0,LED3
    sll     t4,a0,LED4

	la      s0, PORTBCLR
    sw      t1, 0(s0)

    la      s0, prtLed2Clr
    sw      t2, 0(s0)
 
    la      s0, prtLed3Clr
    sw      t3, 0(s0)

    la      s0, prtLed4Clr
    sw      t4, 0(s0)

	lw		s0, 20(sp)
    lw		t4, 16(sp)
    lw		t3, 12(sp)
    lw		t2, 8(sp)
    lw		t1, 4(sp)
    lw		a0, 0(sp)

	addiu	sp, sp, 24

jr		ra
nop

.end mPORTBClear


.ent CheckandSet 
CheckandSet:

/*Write your code here*/
/*Read PORT for checking BTN1*/
CheckBTN1:
    la       s1,prtBtn1
    lw       a1,0( s1)
    addi t0,zero,1
    sll t0,t0,BTN1
    and t1,t0,a1
    beq t1,zero,PasswordVerification
/*turn LED1 on*/  
    addi t0,zero,1
    sll t2,t0,LED1  
    la       s0, prtLed1Set
    sw       t2, 0( s0)

/*clear 8 LEDs*/
    addi sp,sp,-4
    sw ra,0(sp)
    jal mPORTEClear
    nop
    lw ra,0(sp)
    addi sp,sp,4

/*Read PORT for checking BTN2*/
CheckBTN2:
    la       s1,prtBtn2
    lw       a1,0(s1)
    addi t0,zero,1
    sll t0,t0,BTN2
    and t1,t0,a1
    beq t1,zero,CheckBTN2

/*Turn LED1 off*/
    addi t0,zero,1
    sll t2,t0,LED1
    la       s0, prtLed1Clr
    sw       t2, 0(s0)
    
    j PasswordSet
    nop
   
/*Save password*/
PasswordSet:
    addi s2,zero,0
/*Read and check switch1*/
CheckSW1:
    la       s1,prtBtn1p
    lw       a1,0(s1)
    addi t0,zero,1
    sll t3,t0,BTN1p
    and t4,t3,a1
    bne t4,zero,SW1pressed
    nop
    j CheckSW2
    nop
SW1pressed:
    addi s2,zero,1
    
/*Read and check switch2*/
CheckSW2:
    la       s1,prtBtn2p
    lw       a1,0( s1)
    addi t0,zero,1
    sll t3,t0,BTN2p
    and t4,t3,a1
    bne t4,zero,SW2pressed
    nop
    j CheckSW3
    nop
SW2pressed:
    addi s2,zero,2
    
/*Read and check switch3*/
CheckSW3:
    la       s1,prtBtn3p
    lw       a1,0( s1)
    addi t0,zero,1
    sll t3,t0,BTN3p
    and t4,t3,a1
    bne t4,zero,SW3pressed
    nop
    j CheckSW4
    nop
SW3pressed:
    addi s2,zero,4
    
/*Read and check switch4*/
CheckSW4:
    la       s1,prtBtn4p
    lw       a1,0( s1)
    addi t0,zero,1
    sll t3,t0,BTN4p
    and t4,t3,a1
    bne t4,zero,SW4pressed
    nop
    j PasswordVerification
    nop
SW4pressed:
    addi s2,zero,8
    
/*Check password*/
PasswordVerification:
    addi s3,zero,0
/*Read and check switch1*/
CheckSW01:
    la       s1,prtBtn1p
    lw       a1,0( s1)
    addi t0,zero,1
    sll t3,t0,BTN1p
    and t4,t3,a1
    bne t4,zero,SW01pressed
    nop
    j CheckSW02
    nop
SW01pressed:
    addi s3,zero,1
    
/*Read and check switch2*/
CheckSW02:
    la       s1,prtBtn2p
    lw       a1,0( s1)
    addi t0,zero,1
    sll t3,t0,BTN2p
    and t4,t3,a1
    bne t4,zero,SW02pressed
    nop
    j CheckSW03
    nop
SW02pressed:
    addi s3,zero,2

/*Read and check switch3*/
CheckSW03:
    la       s1,prtBtn3p
    lw       a1,0( s1)
    addi t0,zero,1
    sll t3,t0,BTN3p
    and t4,t3,a1
    bne t4,zero,SW03pressed
    nop
    j CheckSW04
    nop
SW03pressed:
    addi s3,zero,4

/*Read and check switch4*/
CheckSW04:
    la       s1,prtBtn4p
    lw       a1,0( s1)
    addi t0,zero,1
    sll t3,t0,BTN4p
    and t4,t3,a1
    bne t4,zero,SW04pressed
    nop
    j Verification
    nop
SW04pressed:
    addi s3,zero,8
    
/*compare if input password is same as set password*/
Verification:
    beq  s2,s3,ON
    nop
    j OFF
    nop

/*Turn on 8 LEDs*/
ON:
    addi sp,sp,-4
    sw ra,0(sp)
    jal mPORTESet
    nop
    lw ra,0(sp)
    addi sp,sp,4
    j end
    nop
/*Turn off 8 LEDs*/
OFF:
    addi sp,sp,-4
    sw ra,0(sp)
    jal mPORTEClear
    nop
    lw ra,0(sp)
    addi sp,sp,4
        
end:    
jr  ra
nop

.end CheckandSet

