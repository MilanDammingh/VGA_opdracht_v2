/*
 * Rectangle.c
 *
 *  Created on: 3 mei 2018
 *      Author: Milan Dammingh
 */

#include "rectangle.h"
#include "line.c"

void draw_rectangle (int x1, int y1, int x2, int y2, byte color)
{
	draw_line(x1, y1, x2, y1, color);
	draw_line(x1, y1, x1, y2, color);
	draw_line(x2, y2, x2, y1, color);
	draw_line(x2, y2, x1, y2, color);

}
