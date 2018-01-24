/*********************************************************************
 *
 *                  Example Assembly Project
 *
 *********************************************************************
 * FileName:        Lab2_1.S
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
addi a1,a0,14;
L1:
add a3,a3,a2;
addi a2,a2,1;
bne a1,a2,L1;



.end main /* directive that marks end of 'main' function and registers
           * size in ELF output
           */
