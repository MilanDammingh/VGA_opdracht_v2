/*
 * terminal_input.c
 *
 *  Created on: 22 mei 2018
 *      Author: Milan Dammingh
 */

#include "terminal_input.h"


void get_data()
{
	UART_gets(functions,TRUE);

	if(strcmp(functions, "line")==0)
	{
		UART_puts("You need to type the following parameter:"
				"x1 y1 x2 y2 color\r"
				"color = VGA_COL_BLUE or VGA_COL_GREEN or VGA_COL_RED or VGA_COL_WHITE or VGA_COL_CYAN or VGA_COL_MAGENTA or VGA_COL_YELLOW\r");
		UART_gets(parameters,TRUE);
		str_check = strtok (parameters," ,");

		while (str_check != NULL)
		{
			UART_puts(str_check);
			UART_puts("\t");
			str_check = strtok (NULL, " ,.-");
		}
	}

	else if(strcmp(functions, "triangle")==0)
	{
		UART_puts("You need to type the following parameter:"
				"x1 y1 x2 y2 x3 y3 color\r");
	}
	else if(strcmp(functions, "rectangle")==0)
	{
		UART_puts("You need to type the following parameter:"
				"x1 y1 x2 y2 color\r");
	}
	else if(strcmp(functions, "ellips")==0)
	{
		UART_puts("You need to type the following parameter:"
				"x_center y_center x_raduis y_radius color\r");
	}
	else if(strcmp(functions, "text")==0)
	{
		UART_puts("You need to type the following parameter:"
				"x1 y1 text font color style\r"
				"style = normal or fat or cursive\r");
	}
	else if(strcmp(functions, "bitmap")==0)
	{
		UART_puts("You need to type the following bitmaps:"
				"\r");
	}
	else if(strcmp(functions, "clr_screen")==0)
	{
		UART_puts("screen_clr_screen\r");
	}

//	else
//		UART_puts("You typed the wrong function, you can choose one of these: line/triangle/rectangle/ellips/text/bitmap/clr_screen\r");

/*

	char * pch;

	pch = strtok (text," ,");
	while (pch != NULL)
	{
//		for(int i=0;i<7;i++)
//			draw[i] = pch;
		UART_puts(pch);
		UART_puts("\t");

		pch = strtok (NULL, " ,.-");
	}
*/

//	for(int j=0;j<7;j++)
//	{
//		UART_puts(draw[j]);
//		UART_puts("\r");
//	}
}
