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

void draw_triangle(int x1,int y1,int x2,int y2,int xtop,int ytop, uint8_t color, uint8_t fill)
{
	//int dx = x1+(abs(x2-x1)>>1);
	//int dy = y1-(x2-x1);

	draw_line(x1,y1,x2,y2,color,1);
	draw_line(x1,y1,xtop,ytop,color,1);
	draw_line(xtop,ytop,x2,y2,color,1);


	if(fill == 1){
		for(int i=x1;i<=50;i++)
			draw_line(i,y1,xtop,ytop,color,1);
		fill=0;
	}

}
