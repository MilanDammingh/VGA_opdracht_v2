//--------------------------------------------------------------
// File     : IO_layer.c
// Datum    : 28.05.2016
// Version  : 1.0
// Autor    : Milan Dammingh
//--------------------------------------------------------------



/*!
 *  This function initializes the VGA screen, the UART and the delay used for this project
 */

#include "IO_layer.h"

/********************************************//**
 *	initializing the hardware and for functions
 ***********************************************/
void IO_Init()
{
	UB_VGA_Screen_Init(); // Init VGA-Screen
	UART_init();
	DELAY_init();
}
