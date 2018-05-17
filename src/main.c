
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
//#include <math.h>
#include "includes.h"


int main(void)
{
	//  uint32_t n;

	SystemInit(); // System speed to 168MHz
	UART_init();
	DELAY_init();
	UB_VGA_Screen_Init(); // Init VGA-Screen

	UB_VGA_FillScreen(VGA_COL_GREEN);

	//draw_line(0,0,100,50,VGA_COL_WHITE, 4);
	draw_rectangle(10,10,50,50,VGA_COL_RED);
	//draw_triangle(10,200,50,100,50,50,VGA_COL_YELLOW,1);
	draw_ellips(120,120,80,100, VGA_COL_WHITE);
	UB_VGA_SetPixel(120,120,VGA_COL_BLACK);

	while(1)
	{
		//UART_puts("\nabc");
		//DELAY_ms(100);
	}
}
