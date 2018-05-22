
//--------------------------------------------------------------
// File     : main.c
// Datum    : 30.03.2016
// Version  : 1.0
// Autor    : UB
// mods by	: J.F. van der Bent
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.x
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_core DMA LIB 320x240, 8bit color
//--------------------------------------------------------------

#include "main.h"
#include "includes.h"


int main(void)
{
	//  uint32_t n;

	SystemInit(); // System speed to 168MHz
	UART_init();
	DELAY_init();
	UB_VGA_Screen_Init(); // Init VGA-Screen

	UB_VGA_FillScreen(VGA_COL_GREEN);


//	draw_triangle(80,40,50,100,150,200,VGA_COL_YELLOW);

	/*
	draw_line(50,0,50,240,VGA_COL_BLACK,1);
	draw_line(100,0,100,240,VGA_COL_BLACK,1);
	draw_line(150,0,150,240,VGA_COL_BLACK,1);
	draw_line(200,0,200,240,VGA_COL_BLACK,1);
	draw_line(250,0,250,240,VGA_COL_BLACK,1);

	draw_line(0,50,320,50,VGA_COL_BLACK,1);
	draw_line(0,100,320,100,VGA_COL_BLACK,1);
	draw_line(0,150,320,150,VGA_COL_BLACK,1);
	draw_line(0,200,320,200,VGA_COL_BLACK,1);
	*/

/*

	draw_line(50,0,50,240,VGA_COL_RED,3); // vertical line
	draw_line(0,50,320,50,VGA_COL_RED,5); // horizontal line
	draw_line(50,50,100,55,VGA_COL_RED,6); // sort of horizontal line
	draw_line(200,200,320,240,VGA_COL_RED,6); // sort of vertical line
	draw_line(100,100,200,200,VGA_COL_RED,11); // diagonal line
*/




	/*
	switch (ipnut[0]){
	case line:
		draw_line(0,0,100,50,VGA_COL_WHITE, 4);
		break;
	case rectangle:
		draw_rectangle(10,10,50,50,VGA_COL_RED);
		break;
	case triangle:
		draw_triangle(10,200,50,100,50,50,VGA_COL_YELLOW,1);
		break;
	case ellips:
		draw_ellips(120,120,80,100, VGA_COL_WHITE);
		break;
	default:
	}
	*/

	UART_puts(	"Welke van de volgende functies wil je gebruiken? "
				"line/triangle/rectangle/ellips/text/bitmap/clr_screen\r");
	char text[100];

	while(1)
	{
		get_data();
//		UART_gets(text,TRUE);
//		UART_puts(text);
	}
}
