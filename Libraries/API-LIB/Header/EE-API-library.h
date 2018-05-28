/*
 * EE-API-library.h
 *
 *  Created on: 28 mei 2018
 *      Author: Milan Dammingh
 */

#ifndef API_LIB_HEADER_EE_API_LIBRARY_H_
#define API_LIB_HEADER_EE_API_LIBRARY_H_

// Includes
//#include "includes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "stm32_ub_vga_screen.h"
#include "delay.h"


// Defines
#define sgn(x) ((x<0)?-1:((x>0)?1:0)) /* macro to return the sign of a
                                         number */
#define TRUE		1
#define FALSE		0

struct arguments {
	char function[10];
	char x1[5];
	char y1[5];
	char x2[5];
	char y2[5];
	char xtop[5];
	char ytop[5];
	char x_center[5];
	char y_center[5];
	char x_rad[5];
	char y_rad[5];
	char thickness[5];
	char text_in[50];
	char bitmap_nr[5];
	char time_ms[5];
	char color[20];
};

struct arguments clearscrn_args;
struct arguments line_args;
struct arguments ellips_args;
struct arguments rectangle_args;
struct arguments triangle_args;
struct arguments text_args;
struct arguments bitmap_args;
struct arguments wait_args;


// Prototype
void clr_screen(uint8_t color);
void draw_line(int x1, int y1, int x2, int y2,  int tn, int color);
void draw_ellips(int x_center, int y_center, int x_rad, int y_rad, int color);
void draw_rectangle (int x1, int y1, int x2, int y2, int color);
void draw_triangle(int x1,int y1,int x2,int y2,int xtop,int ytop, int color);
void draw_text (int x, int y, char text[], int backcolor, int textcolor);  //functie voor het schrijven van tekst
void letter_select(int x, int y, char letter, int backcolor, int textcolor);
void draw_bitmap (int bitmap_selector, int x, int y, int backcolor);
void wait_ms(int time_ms);

#endif /* API_LIB_HEADER_EE_API_LIBRARY_H_ */
