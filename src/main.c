
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
	//_____________________________INIT______________________________________________

	SystemInit(); // System speed to 168MHz
	UB_VGA_Screen_Init(); // Init VGA-Screen

	int backcolor = lichtcyaan;	//achtergrondkleur definieren
	int textcolor = geel;		//textkleur definieren




	//_________________________FUNCTIES OPROEPEN___________________________________

	UB_VGA_FillScreen(backcolor);

	draw_bitmap (65, 50, "happy", backcolor);
	draw_bitmap (10, 50, "sad", backcolor);
	draw_bitmap (150, 170, "up", backcolor);
	draw_bitmap (190, 170, "down", backcolor);
	draw_bitmap (230, 170, "right", backcolor);
	draw_bitmap (280, 170, "left", backcolor);
	draw_text (70, 30, "writing code, it would be fun they said", backcolor, textcolor);

	//UB_VGA_SetPixel(10,10,127);
	//draw_rectangle (0,0,50,50,125);


	while(1)
	{

	}

}
