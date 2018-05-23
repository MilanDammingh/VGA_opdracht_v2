
//--------------------------------------------------------------
// File     : main.c
// Datum    : 30.03.2016
// Version  : 1.0
// Autor    : UB
// mods by	: Samuel Benhaiem and Milan Dammingh
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.x
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_core DMA LIB 320x240, 8bit color
//--------------------------------------------------------------

#include "main.h"
#include "includes.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>


int main(void)
{
	//  uint32_t n;

	SystemInit(); // System speed to 168MHz
	//UART_init();
	//DELAY_init();
	UB_VGA_Screen_Init(); // Init VGA-Screen

	int backcolor = lichtmagenta;
	int textcolor = paars;

	UB_VGA_FillScreen(backcolor);
	//draw_rectangle (0,0,50,50,125);
	draw_bitmap (65, 50, "happy", backcolor);
	draw_bitmap (10, 50, "sad", backcolor);
	draw_bitmap (150, 170, "up", backcolor);
	draw_bitmap (190, 170, "down", backcolor);
	draw_bitmap (230, 170, "right", backcolor);
	draw_bitmap (280, 170, "left", backcolor);

	//UB_VGA_SetPixel(10,10,127);

	draw_text (70, 30, "studenten tien fuck yeah boyy", backcolor, textcolor);

	/*x1 = 50;
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

  while(1)
  {

	UART_puts(	"Welke van de volgende functies wil je gebruiken? "
				"line/triangle/rectangle/ellips/text/bitmap/clr_screen\r");
	char text[100];
*/
	while(1)
	{
//		get_data();
//		UART_gets(text,TRUE);
//		UART_puts(text);
	}
}
