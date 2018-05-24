
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
	UB_VGA_Screen_Init(); // Init VGA-Screen

	int backcolor = lichtcyaan;	//achtergrondkleur definieren
	int textcolor = geel;		//textkleur definieren


	//_________________________FUNCTIES OPROEPEN___________________________________

	UB_VGA_FillScreen(backcolor);

	draw_bitmap (65, 50, 1, backcolor);
	draw_bitmap (10, 50, 2, backcolor);
	draw_bitmap (150, 170, 3, backcolor);
	draw_bitmap (190, 170, 4, backcolor);
	draw_bitmap (230, 170, 5, backcolor);
	draw_bitmap (280, 170, 6, backcolor);
	draw_text (70, 30, "writing code, it would be fun they said", backcolor, textcolor);



	while(1)
	{

	}

}
