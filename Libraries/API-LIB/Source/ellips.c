/*
 * Ellips.c
 *
 *  Created on: May 3, 2018
 *      Author: sam
 */

#include "ellips.h"


#include "stm32_ub_vga_screen.h"


void draw_ellips (int x_center,int y_center, int x_rad, int y_rad, int color)
{
	for(int y=-y_rad; y<=y_rad; y++) {
	    for(int x=-x_rad; x<=x_rad; x++) {
	        if(x*x*y_rad*y_rad+y*y*x_rad*x_rad <= y_rad*y_rad*x_rad*x_rad)
	        	UB_VGA_SetPixel(x_center+x,y_center+y,color);
	    }
	}
}

