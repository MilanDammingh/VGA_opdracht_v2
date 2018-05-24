/*
 * bitmap.h
 *
 *  Created on: 3 mei 2018
 *      Author: Samuel Benhaiem
 */

#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#include "stm32_ub_vga_screen.h"
#include "includes.h"

#ifndef API_LIB_HEADER_BITMAP_H_
#define API_LIB_HEADER_BITMAP_H_

void draw_bitmap (int x, int y, char bitmap_selector[], int backcolor);

#endif /* API_LIB_HEADER_BITMAP_H_ */
