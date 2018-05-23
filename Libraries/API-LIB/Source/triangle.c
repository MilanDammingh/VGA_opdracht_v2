/*
 * Triangle.c
 *
 *  Created on: 3 mei 2018
 *      Author: Milan Dammingh
 */

#include "triangle.h"
#include "line.h"
#include "stm32_ub_vga_screen.h"
#include <stdlib.h>
#include "includes.h"

void draw_triangle(int x1,int y1,int x2,int y2,int xtop,int ytop, uint8_t color)
{
	int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;

	dx=x2-x1;      /* the horizontal distance of the line */
	dy=y2-y1;      /* the vertical distance of the line */
	dxabs=abs(dx);
	dyabs=abs(dy);

	draw_line(x1,y1,x2,y2,rood,1);

	//xtop,ytop naar x1,y1 tot x2,y2,




	for(int i=x1;i<=x2;i++)
		draw_line(i,y2,xtop,ytop,color,1);
}
