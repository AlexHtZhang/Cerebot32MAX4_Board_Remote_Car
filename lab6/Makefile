# MPLAB IDE generated this makefile for use with GNU make.
# Project: lab6.S.mcp
# Date: Fri Mar 20 12:49:30 2015

AS = pic32-as.exe
CC = pic32-gcc.exe
LD = pic32-ld.exe
AR = pic32-ar.exe
HX = pic32-bin2hex.exe
RM = rm

lab6.S.hex : lab6.S.elf
	$(HX) "lab6.S.elf"

lab6.S.elf : lab6.o
	$(CC) -mprocessor=32MX460F512L "lab6.o" -o"lab6.S.elf" -Wl,-L"C:\Apps\MPLAB\MPLAB C32 Suite\lib",-L"C:\Apps\MPLAB\MPLAB C32 Suite\pic32mx\lib",--defsym=__MPLAB_BUILD=1,-Map="lab6.S.map"

lab6.o : lab6.S config.h
	$(CC) -mprocessor=32MX460F512L -c -MMD -MF"lab6.d" "lab6.S" -o"lab6.o" -Wa,-gdwarf-2

clean : 
	$(RM) "lab6.o" "lab6.S.elf" "lab6.S.hex"

