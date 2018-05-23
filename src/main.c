
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
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include "line.h"
#include "text.h"


int main(void)
{
	//  uint32_t n;

	SystemInit(); // System speed to 168MHz
	UART_init();
	DELAY_init();
	UB_VGA_Screen_Init(); // Init VGA-Screen

	UB_VGA_FillScreen(VGA_COL_BLACK);
	//draw_rectangle (0,0,50,50,125);
	draw_bitmap (50, 50);

	/*
	UB_VGA_SetPixel(10,10,127);

	draw_text (70, 30, "MILAN JE BENT EEN KANKER NEGER");

	x1 = 50;
	y1 = 50;
	x2 = 100;
	y2 = 100;

	for(i=x1;i<=x2;i++)
		UB_VGA_SetPixel(i,y1,127);
	for(j=x1;j<=x2;j++)
		UB_VGA_SetPixel(j,y2,200);
	for(k=y1;k<=y2;k++)
		UB_VGA_SetPixel(x1,k,50);
	for(l=y1;l<=y2;l++)
		UB_VGA_SetPixel(x2,l,255);
	*/
  while(1)
  {

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
