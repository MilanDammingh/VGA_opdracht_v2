/*
 * clr_screen.c
 *
 *  Created on: 3 mei 2018
 *      Author: Milan Dammingh
 */

#include "clr_screen.h"

void clr_screen(uint8_t color)
{
	UB_VGA_FillScreen(color);
}
