/*********************************************************************
 *
 *                  Example Assembly Project
 *
 *********************************************************************
 * FileName:        Lab2.S
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

add a2,a0,a1;
addi a3,a1,1;
sub s0,a3,a2;
and s2,s0,s1;
or s3,s0,s1;
xor s4,s0,s1;
nor s5,s0,s1;

beq s3,s4,L1;
L1:
add k0,s3,s4;

bne s3,s4,L2;
L2:
sub k1,s3,s4;




.end main /* directive that marks end of 'main' function and registers
           * size in ELF output
           */
