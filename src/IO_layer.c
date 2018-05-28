/*
 * IO_layer.c
 *
 *  Created on: 28 mei 2018
 *      Author: Milan Dammingh
 */
#include "IO_layer.h"

void IO_Init()
{
	UB_VGA_Screen_Init(); // Init VGA-Screen
	UART_init();
	DELAY_init();
}
