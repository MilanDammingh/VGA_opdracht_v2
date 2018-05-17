/*
 * Rectangle.c
 *
 *  Created on: 3 mei 2018
 *      Author: Milan Dammingh
 */

#include "rectangle.h"
#include "line.h"

void draw_rectangle (int x1, int y1, int x2, int y2, uint8_t color)
{
	x1 = x1 - 1;
	x2 = x2 + 10;
	for(int i=y1;i<=y2;i++)
	{
		for(int j=x1;j<=x2;j++)
		{
			UB_VGA_SetPixel(j,i,color);
		}
	}
	/*
	draw_line(x1, y1, x2, y1, color,1);
	draw_line(x1, y1, x1, y2, color,1);
	draw_line(x2, y2, x2, y1, color,1);
	draw_line(x2, y2, x1, y2, color,1);
	*/
}
