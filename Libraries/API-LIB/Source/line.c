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

void draw_line(int x1, int y1, int x2, int y2, int tn, int color)
{

	int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;
	uint8_t stn,tn_draw;

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

	stn = ((tn%2)==0)? 1:0;  /* even of oneven lijndikte */
	tn_draw = tn>>1;

	if (dxabs>=dyabs) 	/* the line is more horizontal than vertical */
	{
		if(stn==1) /* even line thickness */
		{
			px=x1;
			py=y1;
			for(i=0;i<=dxabs;i++)								/* for loop van 0 tot en met het verschil van de pixels */
			{
				y+=dyabs;										/* adding dyabs for drawing vertical pixel */
				if (y>=dxabs)									/* y is higher than the dxabs of line, so py counting -1/0/1 */
				{
					y-=dxabs;									/* substracting dxabs of y so counting is reset */
					py+=sdy;
				}
				for(int k=-tn_draw;k<tn_draw;k++)
				{
					if(px>=0 && px <= 320 && py>=0 && py <= 240)	/* pixels inside range VGA screen will be drawn */
					{
						UB_VGA_SetPixel(px+k,py-k,color);
						UB_VGA_SetPixel(px+k,py-k-1,color);
					}
				}
				px+=sdx; 										/* -1/0/1 counting pixel */
			}
		}
		else if(stn==0)	/* odd line thickness */
		{
			px=x1;
			py=y1;
			for(i=0;i<=dxabs;i++)								/* for loop van 0 tot en met het verschil van de pixels */
			{
				y+=dyabs;										/* adding dyabs for drawing vertical pixel */
				if (y>=dxabs)									/* y is higher than the dxabs of line, so py counting -1/0/1 */
				{
					y-=dxabs;									/* substracting dxabs of y so counting is reset */
					py+=sdy;
				}
				for(int h=0-tn_draw;h<=tn_draw;h++)
				{
					if(px>=0 && px <= 320 && py>=0 && py <= 240)	/* pixels inside range VGA screen will be drawn */
					{
						UB_VGA_SetPixel(px+h,py-h,color);
						UB_VGA_SetPixel(px+h,py-h-1,color);
					}
				}
				px+=sdx; 										/* -1/0/1 counting pixel */
			}
		}
	}

	else	/* the line is more vertical than horizontal */
	{
		if(stn==1) /* even line thickness */
		{
			px=x1;
			py=y1;
			for(i=0;i<=dxabs;i++)								/* for loop van 0 tot en met het verschil van de pixels */
			{
				y+=dyabs;										/* adding dyabs for drawing vertical pixel */
				if (y>=dxabs)									/* y is higher than the dxabs of line, so py counting -1/0/1 */
				{
					y-=dxabs;									/* substracting dxabs of y so counting is reset */
					py+=sdy;
				}
				for(int k=0-tn_draw;k<tn_draw;k++)
				{
					if(px>=0 && px <= 320 && py>=0 && py <= 240)	/* pixels inside range VGA screen will be drawn */
					{
						UB_VGA_SetPixel(px+k,py-k,color);
						UB_VGA_SetPixel(px+k,py-k-1,color);
					}
				}
				px+=sdx; 										/* -1/0/1 counting pixel */
			}
		}
		else if(stn==0)	/* odd line thickness */
		{
			px=x1;
			py=y1;
			for(i=0;i<=dyabs;i++)								/* for loop van 0 tot en met het verschil van de pixels */
			{
				x+=dxabs;										/* adding dyabs for drawing vertical pixel */
				if (x>=dyabs)									/* y is higher than the dxabs of line, so py counting -1/0/1 */
				{
					x-=dyabs;									/* substracting dxabs of y so counting is reset */
					px+=sdx;
				}
				for(int h=0-tn_draw;h<=tn_draw;h++)
				{
					if(px>=0 && px <= 320 && py>=0 && py <= 240)	/* pixels inside range VGA screen will be drawn */
					{
						UB_VGA_SetPixel(px+h,py-h,color);
						UB_VGA_SetPixel(px+h,py-h-1,color);
					}
				}
				py+=sdy; 										/* -1/0/1 counting pixel */
			}
		}
	}
}

