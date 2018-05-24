/*
 * letter_select.h
 *
 *  Created on: May 23, 2018
 *      Author: sam
 */

#include <stdio.h>
#include <stdlib.h>
#include "stm32_ub_vga_screen.h"
#include "includes.h"

#ifndef API_LIB_HEADER_LETTER_SELECT_H_
#define API_LIB_HEADER_LETTER_SELECT_H_

void letter_select(int x, int y, char letter, int backcolor, int frontcolor);

#endif /* API_LIB_HEADER_LETTER_SELECT_H_ */
