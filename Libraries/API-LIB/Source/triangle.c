/*
 * Triangle.c
 *
 *  Created on: 3 mei 2018
 *      Author: Milan Dammingh
 */

#include "triangle.h"
#include "line.h"
#include "stm32_ub_vga_screen.h"

void draw_triangle(int x1,int y1,int x2,int y2,int xtop,int ytop, uint8_t color, uint8_t fill)
{
	draw_line(x1,y1,x2,y2,color);
	draw_line(x1,y1,x2>>1,y2>>1,color);
	draw_line(x2>>1,y2>>1,x2,y2,color);
}
