/*
 * text.h
 *
 *  Created on: 3 mei 2018
 *      Author: Samuel Benhaiem
 */

#include "stm32_ub_vga_screen.h"
#include <stdio.h>
#include <stdlib.h>
#include "letter_select.h"

#ifndef API_LIB_HEADER_TEXT_H_
#define API_LIB_HEADER_TEXT_H_

void draw_text (int x, int y, char text[], int backcolor, int textcolor);
// Includes
#include "includes.h"
void letter_select(int x, int y, char letter);
// Prototype


#endif /* API_LIB_HEADER_TEXT_H_ */
