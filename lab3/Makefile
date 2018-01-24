# MPLAB IDE generated this makefile for use with GNU make.
# Project: lab3.S.mcp
# Date: Fri Feb 06 13:36:50 2015

AS = pic32-as.exe
CC = pic32-gcc.exe
LD = pic32-ld.exe
AR = pic32-ar.exe
HX = pic32-bin2hex.exe
RM = rm

lab3.S.hex : lab3.S.elf
	$(HX) "lab3.S.elf"

lab3.S.elf : lab3.o
	$(CC) -mprocessor=32MX460F512L "lab3.o" -o"lab3.S.elf" -Wl,-L"C:\Apps\MPLAB\MPLAB C32 Suite\lib",-L"C:\Apps\MPLAB\MPLAB C32 Suite\pic32mx\lib",--defsym=__MPLAB_BUILD=1,-Map="lab3.S.map"

lab3.o : lab3.S config.h
	$(CC) -mprocessor=32MX460F512L -c -MMD -MF"lab3.d" "lab3.S" -o"lab3.o" -Wa,-gdwarf-2

clean : 
	$(RM) "lab3.o" "lab3.S.elf" "lab3.S.hex"

