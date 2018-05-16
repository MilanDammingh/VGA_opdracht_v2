/*
 * Line.c
 *
 *  Created on: May 3, 2018
 *      Author: Milan
 */

#include "line.h"
#include "stm32_ub_vga_screen.h"

#include <stdio.h>
#include <stdlib.h>

void draw_line(int x1, int y1, int x2, int y2, uint8_t color)
{

	int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;

	dx=x2-x1;      /* the horizontal distance of the line */
	dy=y2-y1;      /* the vertical distance of the line */
	dxabs=abs(dx);
	dyabs=abs(dy);
	sdx=sgn(dx);
	sdy=sgn(dy);
	x=dyabs>>1;
	y=dxabs>>1;
	px=x1;
	py=y1;

	//VGA[(py<<8)+(py<<6)+px]=color;

	if (dxabs>=dyabs) /* the line is more horizontal than vertical */
	{
		for(i=0;i<=dxabs;i++)
		{
			if(px>=0 && py>=0)
				UB_VGA_SetPixel(px,py,color);
			y+=dyabs;
			if (y>=dxabs)
			{
				y-=dxabs;
				py+=sdy;
			}
			px+=sdx;
		}
	}
	else /* the line is more vertical than horizontal */
	{
		for(i=0;i<=dyabs;i++)
		{
			if(px>=0 && py>=0)
				UB_VGA_SetPixel(px,py,color);
			x+=dxabs;
			if (x>=dyabs)
			{
			x-=dyabs;
			px+=sdx;
			}
			py+=sdy;
		}
	}
}

