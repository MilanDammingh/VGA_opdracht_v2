/*
 * IO_layer.c
 *
 *  Created on: 28 mei 2018
 *      Author: Milan Dammingh & Samuel Benhaiem
 */



/*!
 *  The IO_init initializes the VGA screen, the UART and the delay used for this project
 */

#include "IO_layer.h"

void IO_Init()
{
	UB_VGA_Screen_Init(); // Init VGA-Screen
	UART_init();
	DELAY_init();
}
