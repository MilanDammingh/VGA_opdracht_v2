/*
 * Rectangle.c
 *
 *  Created on: 3 mei 2018
 *      Author: Milan Dammingh
 */

#include "rectangle.h"
#include "line.h"

void draw_rectangle (int x1, int y1, int x2, int y2, int color)
{
	for(int i=y1;i<=y2;i++)
	{
		for(int j=x1;j<=x2;j++)
			UB_VGA_SetPixel(j,i,color);
	}
}
