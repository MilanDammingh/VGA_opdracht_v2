/*
 * logic_layer.c
 *
 *  Created on: 24 mei 2018
 *      Author: Milan Dammingh
 */
#include "logic_layer.h"



int color(char *color_input)
{
	if(strcmp(color_input, "zwart")==0) return zwart;
	else if(strcmp(color_input, "blauw")==0) return blauw;
	else if(strcmp(color_input, "lichtblauw")==0) return lichtblauw;
	else if(strcmp(color_input, "groen")==0) return groen;
	else if(strcmp(color_input, "lichtgroen")==0) return lichtgroen;
	else if(strcmp(color_input, "rood")==0) return rood;
	else if(strcmp(color_input, "lichtrood")==0) return lichtrood;
	else if(strcmp(color_input, "wit")==0) return wit;
	else if(strcmp(color_input, "cyaan")==0) return cyaan;
	else if(strcmp(color_input, "lichtcyaan")==0) return lichtcyaan;
	else if(strcmp(color_input, "magenta")==0) return magenta;
	else if(strcmp(color_input, "lichtmagenta")==0) return lichtmagenta;
	else if(strcmp(color_input, "geel")==0) return geel;
	else if(strcmp(color_input, "bruin")==0) return bruin;
	else if(strcmp(color_input, "grijs")==0) return grijs;
	else if(strcmp(color_input, "paars")==0) return paars;
	else return paars;
};


void func_chooser()
{
	if(!strcmp(clearscrn_args.function,"clearscherm"))
	{
//		UART_puts("function = "); UART_puts(clearscrn_args.function); UART_puts("\r");
		clr_screen(color(clearscrn_args.color));

		for(int i=0;i<sizeof(clearscrn_args.function);i++)
			clearscrn_args.function[i] = 0;
	}
	else if(!strcmp(line_args.function,"lijn"))
	{
//		UART_puts("function = "); UART_puts(line_args.function); UART_puts("\r");
		draw_line(atoi(line_args.x1),atoi(line_args.y1),atoi(line_args.x2),atoi(line_args.y2),atoi(line_args.thickness),color(line_args.color));

		for(int i=0;i<sizeof(line_args.function);i++)
			line_args.function[i] = 0;

	}
	else if(!strcmp(ellips_args.function,"ellips"))
	{
//		UART_puts("function = "); UART_puts(ellips_args.function); UART_puts("\r");
		draw_ellips(atoi(ellips_args.x_center),atoi(ellips_args.y_center),atoi(ellips_args.x_rad),atoi(ellips_args.y_rad),color(ellips_args.color));

		for(int i=0;i<sizeof(ellips_args.function);i++)
			ellips_args.function[i] = 0;
	}
	else if(!strcmp(rectangle_args.function,"rechthoek"))
	{
//		UART_puts("function = "); UART_puts(rectangle_args.function); UART_puts("\r");
		draw_rectangle(atoi(rectangle_args.x1),atoi(rectangle_args.y1),atoi(rectangle_args.x2),atoi(rectangle_args.y2),color(rectangle_args.color));

		for(int i=0;i<sizeof(rectangle_args.function);i++)
			rectangle_args.function[i] = 0;
	}
	else if(!strcmp(triangle_args.function,"driehoek"))
	{
//		UART_puts("function = "); UART_puts(triangle_args.function); UART_puts("\r");
		draw_triangle(atoi(triangle_args.x1),atoi(triangle_args.y1),atoi(triangle_args.x2),atoi(triangle_args.y2),atoi(triangle_args.xtop),atoi(triangle_args.ytop),color(triangle_args.color));

		for(int i=0;i<sizeof(triangle_args.function);i++)
			triangle_args.function[i] = 0;
	}
	else if(!strcmp(text_args.function,"tekst"))
	{
//		UART_puts("function = "); UART_puts(text_args.function); UART_puts("\r");
		for(int i=0;i<sizeof(text_args.function);i++)
			text_args.function[i] = 0;

		draw_text(atoi(text_args.x1),atoi(text_args.y1),text_args.text_in,color(clearscrn_args.color),color(text_args.color));
	}
	else if(!strcmp(bitmap_args.function,"bitmap"))
	{
//		UART_puts("function = "); UART_puts(bitmap_args.function); UART_puts("\r");
		draw_bitmap(atoi(bitmap_args.bitmap_nr),atoi(bitmap_args.x1),atoi(bitmap_args.y1),color(clearscrn_args.color));

		for(int i=0;i<sizeof(bitmap_args.function);i++)
			bitmap_args.function[i] = 0;
	}
	else if(!strcmp(wait_args.function,"wacht"))
	{
//		UART_puts("function = "); UART_puts(wait_args.function); UART_puts("\r");
		wait_ms(atoi(wait_args.time_ms));

		for(int i=0;i<sizeof(wait_args.function);i++)
			wait_args.function[i] = 0;


	}
	else
	{
		// Error handling
//		UART_puts("error handling");
	}
}


