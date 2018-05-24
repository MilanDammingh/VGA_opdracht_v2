
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



int main(void)
{
	//_____________________________INIT______________________________________________


	SystemInit(); // System speed to 168MHz
	UART_init();
	DELAY_init();
	UB_VGA_Screen_Init(); // Init VGA-Screen

	//_________________________FUNCTIES OPROEPEN___________________________________
	UB_VGA_FillScreen(zwart);

	while(1)
	{
		get_data(); // front_layer(); // input terminal

		if(clearscrn_args.function != 0)
		{
			UART_puts("function = "); UART_puts(clearscrn_args.function); UART_puts("\r");
		}
		else if(line_args.function != 0)
		{
			UART_puts("function = "); UART_puts(line_args.function); UART_puts("\r");
		}
		else if(ellips_args.function != 0)
		{
			UART_puts("function = "); UART_puts(ellips_args.function); UART_puts("\r");
		}
//			UART_puts("function = "); UART_puts(ellips_args.function); UART_puts("\r");
//			UART_puts("function = "); UART_puts(rectangle_args.function); UART_puts("\r");
//			UART_puts("function = "); UART_puts(triangle_args.function); UART_puts("\r");
//			UART_puts("function = "); UART_puts(text_args.function); UART_puts("\r");
//			UART_puts("function = "); UART_puts(bitmap_args.function); UART_puts("\r");
//			UART_puts("function = "); UART_puts(wait_args.function); UART_puts("\r");


//		logic_layer(); //oproepen_functies();
//		io_layer(); // UB_VGA_SetPixel(xp,yp,color);
	}

}
