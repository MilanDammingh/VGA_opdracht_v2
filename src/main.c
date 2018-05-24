
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

	int backcolor = lichtcyaan;	//achtergrondkleur definieren
	int textcolor = geel;		//textkleur definieren


	//_________________________FUNCTIES OPROEPEN___________________________________

	UB_VGA_FillScreen(backcolor);

	draw_bitmap (0,65, 50, backcolor);
	draw_bitmap (1, 10, 50, backcolor);
	draw_bitmap (2, 150, 170, backcolor);
	draw_bitmap (3, 190, 170, backcolor);
	draw_bitmap (4, 230, 170, backcolor);
	draw_bitmap (5, 280, 170, backcolor);
	draw_text (70, 30, "writing code, it would be fun they said", backcolor, textcolor);

	draw_line(10,100,100,200,4,rood);


	while(1)
	{
		get_data();
	}

}
