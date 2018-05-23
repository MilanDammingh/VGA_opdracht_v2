/*
 * terminal_input.c
 *
 *  Created on: 22 mei 2018
 *      Author: Milan Dammingh
 */

#include "terminal_input.h"

int color(char *color_input);



void get_data() //krijg je hier geen argumenten binnen?
{
	int fill=0;

	UART_gets(parameters,TRUE);
	UART_puts("input = "); UART_puts(parameters); UART_puts("\r");
	token = strtok (parameters,",");
	strcpy(functions,token);

	if(strcmp(functions, "clearscherm")==0)
	{
		fill=0;
		UART_puts("clearscherm\r");
		while(token != NULL)
		{
		  switch(fill)
		  {
			case 0:
			  strcpy(functions,token);
			  break;
			case 1:
			  strcpy(clearscrn_args.color,token);
			  break;
		  }
		  fill++;
		  token = strtok (NULL, ",");
		}
//	    clearscreen(color(clearscrn_args.color));
		UART_puts("color = "); UART_puts(clearscrn_args.color); UART_puts("\r");
	}
	else if(strcmp(functions, "lijn")==0)
	{
		fill=0;
		UART_puts("lijn\r");
		while(token!= NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(functions,token);
					break;
				case 1:
					strcpy(line_args.x1,token);
					break;
				case 2:
					strcpy(line_args.y1,token);
					break;
				case 3:
					strcpy(line_args.x2,token);
					break;
				case 4:
					strcpy(line_args.y2,token);
					break;
				case 5:
					strcpy(line_args.thickness,token);
					break;
				case 6:
					strcpy(line_args.color,token);
					break;
			}
			fill++;
			token = strtok (NULL, ",");
		}
		draw_line(atoi(line_args.x1),atoi(line_args.y1),atoi(line_args.x2),atoi(line_args.y2),atoi(line_args.thickness),color(line_args.color));

		UART_puts("x1 = "); UART_puts(line_args.x1); UART_puts("\r");
		UART_puts("y1 = "); UART_puts(line_args.y1); UART_puts("\r");
		UART_puts("x2 = "); UART_puts(line_args.x2); UART_puts("\r");
		UART_puts("y2 = "); UART_puts(line_args.y2); UART_puts("\r");
		UART_puts("thickness = "); UART_puts(line_args.thickness); UART_puts("\r");
		UART_puts("color = "); UART_puts(line_args.color); UART_puts("\r");
	}
	else if(strcmp(functions, "ellips")==0)
	{
		fill=0;
		UART_puts("ellips\r");
		while(token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(functions,token);
					break;
				case 1:
					strcpy(ellips_args.x_center,token);
					break;
				case 2:
					strcpy(ellips_args.y_center,token);
					break;
				case 3:
					strcpy(ellips_args.x_rad,token);
					break;
				case 4:
					strcpy(ellips_args.y_rad,token);
					break;
				case 5:
					strcpy(ellips_args.color,token);
					break;
			}
			fill++;
			token = strtok (NULL, ",");
		}
		draw_ellips(atoi(ellips_args.x_center),atoi(ellips_args.y_center),atoi(ellips_args.x_rad),atoi(ellips_args.y_rad),color(ellips_args.color));
		UART_puts("x_center = "); UART_puts(ellips_args.x_center); UART_puts("\r");
		UART_puts("y_center = "); UART_puts(ellips_args.y_center); UART_puts("\r");
		UART_puts("x_rad = "); UART_puts(ellips_args.x_rad); UART_puts("\r");
		UART_puts("y_rad = "); UART_puts(ellips_args.y_rad); UART_puts("\r");
		UART_puts("color = "); UART_puts(ellips_args.color); UART_puts("\r");
	}
	else if(strcmp(functions, "rechthoek")==0)
	{
		fill=0;
		UART_puts("rechthoek\r");
		while(token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(functions,token);
					break;
				case 1:
					strcpy(rectangle_args.x1,token);
					break;
				case 2:
					strcpy(rectangle_args.y1,token);
					break;
				case 3:
					strcpy(rectangle_args.x2,token);
					break;
				case 4:
					strcpy(rectangle_args.y2,token);
					break;
				case 5:
					strcpy(rectangle_args.color,token);
					break;
			}
			fill++;
			token = strtok (NULL, ",");
		}
		draw_rectangle(atoi(rectangle_args.x1),atoi(rectangle_args.y1),atoi(rectangle_args.x2),atoi(rectangle_args.y2),color(rectangle_args.color));
		UART_puts("x1 = "); UART_puts(rectangle_args.x1); UART_puts("\r");
		UART_puts("y1 = "); UART_puts(rectangle_args.y1); UART_puts("\r");
		UART_puts("x2 = "); UART_puts(rectangle_args.x2); UART_puts("\r");
		UART_puts("y2 = "); UART_puts(rectangle_args.y2); UART_puts("\r");
		UART_puts("color = "); UART_puts(rectangle_args.color); UART_puts("\r");
	}
	else if(strcmp(functions, "driehoek")==0)
	{
		fill=0;
		UART_puts("driehoek\r");
		while(token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(functions,token);
					break;
				case 1:
					strcpy(triangle_args.x1,token);
					break;
				case 2:
					strcpy(triangle_args.y1,token);
					break;
				case 3:
					strcpy(triangle_args.x2,token);
					break;
				case 4:
					strcpy(triangle_args.y2,token);
					break;
				case 5:
					strcpy(triangle_args.xtop,token);
					break;
				case 6:
					strcpy(triangle_args.ytop,token);
					break;
				case 7:
					strcpy(rectangle_args.color,token);
					break;
			}
			fill++;
			token = strtok (NULL, ",");
		}
		draw_triangle(atoi(triangle_args.x1),atoi(triangle_args.y1),atoi(triangle_args.x2),atoi(triangle_args.y2),atoi(triangle_args.xtop),atoi(triangle_args.ytop),color(triangle_args.color));
		UART_puts("x1 = "); UART_puts(rectangle_args.x1); UART_puts("\r");
		UART_puts("y1 = "); UART_puts(rectangle_args.y1); UART_puts("\r");
		UART_puts("x2 = "); UART_puts(rectangle_args.x2); UART_puts("\r");
		UART_puts("y2 = "); UART_puts(rectangle_args.y2); UART_puts("\r");
		UART_puts("xtop = "); UART_puts(rectangle_args.xtop); UART_puts("\r");
		UART_puts("ytop = "); UART_puts(rectangle_args.ytop); UART_puts("\r");
		UART_puts("color = "); UART_puts(rectangle_args.color); UART_puts("\r");
	}
	else if(strcmp(functions, "tekst")==0)
	{
		fill=0;
		UART_puts("tekst\r");
		while(token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(functions,token);
					break;
				case 1:
					strcpy(text_args.x1,token);
					break;
				case 2:
					strcpy(text_args.y1,token);
					break;
				case 3:
					strcpy(text_args.text_in,token);
					break;
			}
			fill++;
			token = strtok (NULL, ",");
		}
		draw_text(atoi(text_args.x1),atoi(text_args.y1),text_args.text_in);

		UART_puts("x1 = "); UART_puts(text_args.x1); UART_puts("\r");
		UART_puts("y1 = "); UART_puts(text_args.y1); UART_puts("\r");
		UART_puts("text_in = "); UART_puts(text_args.text_in); UART_puts("\r");
	}
	else if(strcmp(functions, "bitmap")==0)
	{
		fill=0;
		UART_puts("bitmap\r");
		while(token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(functions,token);
					break;
				case 1:
					strcpy(bitmap_args.bitmap_nr,token);
					break;
				case 2:
					strcpy(bitmap_args.x1,token);
					break;
				case 3:
					strcpy(bitmap_args.y1,token);
					break;
			}
			fill++;
			token = strtok (NULL, ",");
		}
		draw_bitmap(/*atoi(bitmap.bitmap_nr),*/atoi(bitmap_args.x1),atoi(bitmap_args.y1));
		UART_puts("x1 = "); UART_puts(bitmap_args.x1); UART_puts("\r");
		UART_puts("y1 = "); UART_puts(bitmap_args.y1); UART_puts("\r");
		UART_puts("bitmap_nr = "); UART_puts(bitmap_args.bitmap_nr); UART_puts("\r");

	}
	else if(strcmp(functions, "wacht")==0)
	{
		fill=0;
		UART_puts("wacht\r");
		while(token != NULL)
		{
			switch(fill)
			{
			case 0:
				strcpy(functions,token);
				break;
			case 1:
				strcpy(wait_args.time_ms,token);
				break;
			}
			fill++;
			token = strtok (NULL, ",");
		}
//    	wait_ms(atoi(wait_args.time_ms));
		UART_puts("time_ms = "); UART_puts(wait_args.time_ms); UART_puts("\r");
	}

}

int color(char *color_input)
{
	if(strcmp(line_args.color, "zwart")==0) return zwart;
	else if(strcmp(line_args.color, "blauw\r")==0) return blauw;
	else if(strcmp(line_args.color, "lichtblauw")==0) return lichtblauw;
	else if(strcmp(line_args.color, "groen")==0) return groen;
	else if(strcmp(line_args.color, "groen\r")==0) return groen;
	else if(strcmp(line_args.color, "lichtgroen")==0) return lichtgroen;
	else if(strcmp(line_args.color, "rood")==0) return rood;
	else if(strcmp(line_args.color, "lichtrood")==0) return lichtrood;
	else if(strcmp(line_args.color, "wit")==0) return wit;
	else if(strcmp(line_args.color, "cyaan")==0) return cyaan;
	else if(strcmp(line_args.color, "lichtcyaan")==0) return lichtcyaan;
	else if(strcmp(line_args.color, "magenta")==0) return magenta;
	else if(strcmp(line_args.color, "lichtmagenta")==0) return lichtmagenta;
	else if(strcmp(line_args.color, "geel")==0) return geel;
	else if(strcmp(line_args.color, "bruin")==0) return bruin;
	else if(strcmp(line_args.color, "grijs")==0) return grijs;
	else if(strcmp(line_args.color, "paars")==0) return paars;
	else return wit;
};
