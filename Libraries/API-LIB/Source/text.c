/*
 * text.c
 *
 *  Created on: 3 mei 2018
 *      Author: Samuel Benhaiem
 */

#include "text.h"
#include "stm32_ub_vga_screen.h"

#include <stdio.h>
#include <stdlib.h>
#include "letter_select.h"


void draw_text (int x, int y, char text[], int backcolor, int textcolor) {

	for(int i=0;i<strlen(text);i++)
	{
		letter_select(x,y,text[i], backcolor, textcolor);
		x = x + 5;
	}
}
