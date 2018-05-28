
//--------------------------------------------------------------
// File     : main.c
// Datum    : 30.03.2016
// Version  : 1.0
// Autor    : UB
// mods by	: Samuel Benhaiem and Milan Dammingh
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.x
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_core DMA LIB 320x240, 8bit color
//--------------------------------------------------------------

#include "main.h"

int main(void)
{
	//_____________________________INIT______________________________________________
	SystemInit(); // System speed to 168MHz
	IO_Init();

	while(1)
	{
		input_uart();
	}
}
