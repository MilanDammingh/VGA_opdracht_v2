/*
 * front_layer.c
 *
 *  Created on: 28 mei 2018
 *      Author: Milan Dammingh
 */
#include "front_layer.h"

void input_uart()
{
	int fill;
	UART_gets(parameters,TRUE);		// Get data from terminal
	fl_token = strtok (parameters,",");	// Put first argument in fl_token
	strcpy(functions,fl_token);			// String compare to functions
	error_handling_1();

	if(strcmp(functions, "clearscherm")==0)	// Function is clearscreen
	{
		fill=0;
		while(fl_token != NULL)				// While something in fl_token execute code below
		{
		  switch(fill)						// Fill char string with each parameter
		  {
			case 0:
			  strcpy(clearscrn_args.function,fl_token);
			  break;
			case 1:
			  strcpy(clearscrn_args.color,fl_token);
			  break;
		  }
		  fill++;
		  fl_token = strtok (NULL, ",");
		}
		if(fill<LEN_CLEARSCRN_ARG)
			UART_puts("ERROR 3: to few arguments were given\r");
		else if(fill>LEN_CLEARSCRN_ARG)
			UART_puts("ERROR 4: to many arguments were given\r");
		error_handling_2();
		func_chooser();
	}
	else if(strcmp(functions, "lijn")==0)
	{
		fill=0;
		while(fl_token!= NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(line_args.function,fl_token);
					break;
				case 1:
					strcpy(line_args.x1,fl_token);
					break;
				case 2:
					strcpy(line_args.y1,fl_token);
					break;
				case 3:
					strcpy(line_args.x2,fl_token);
					break;
				case 4:
					strcpy(line_args.y2,fl_token);
					break;
				case 5:
					strcpy(line_args.thickness,fl_token);
					break;
				case 6:
					strcpy(line_args.color,fl_token);
					break;
			}
			fill++;
			fl_token = strtok (NULL, ",");
		}
		if(fill<LEN_LINE_ARG)
			UART_puts("ERROR 3: to few arguments were given\r");
		else if(fill>LEN_LINE_ARG)
			UART_puts("ERROR 4: to many arguments were given\r");
		error_handling_2();
		func_chooser();
	}
	else if(strcmp(functions, "ellips")==0)
	{
		fill=0;
		while(fl_token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(ellips_args.function,fl_token);
					break;
				case 1:
					strcpy(ellips_args.x_center,fl_token);
					break;
				case 2:
					strcpy(ellips_args.y_center,fl_token);
					break;
				case 3:
					strcpy(ellips_args.x_rad,fl_token);
					break;
				case 4:
					strcpy(ellips_args.y_rad,fl_token);
					break;
				case 5:
					strcpy(ellips_args.color,fl_token);
					break;
			}
			fill++;
			fl_token = strtok (NULL, ",");
		}
		if(fill<LEN_ELLIPS_ARG)
			UART_puts("ERROR 3: to few arguments were given\r");
		else if(fill>LEN_ELLIPS_ARG)
			UART_puts("ERROR 4: to many arguments were given\r");
		error_handling_2();
		func_chooser();
	}
	else if(strcmp(functions, "rechthoek")==0)
	{
		fill=0;
		while(fl_token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(rectangle_args.function,fl_token);
					break;
				case 1:
					strcpy(rectangle_args.x1,fl_token);
					break;
				case 2:
					strcpy(rectangle_args.y1,fl_token);
					break;
				case 3:
					strcpy(rectangle_args.x2,fl_token);
					break;
				case 4:
					strcpy(rectangle_args.y2,fl_token);
					break;
				case 5:
					strcpy(rectangle_args.color,fl_token);
					break;
			}
			fill++;
			fl_token = strtok (NULL, ",");
		}
		if(fill<LEN_RECTANGLE_ARG)
			UART_puts("ERROR 3: to few arguments were given\r");
		else if(fill>LEN_RECTANGLE_ARG)
			UART_puts("ERROR 4: to many arguments were given\r");
		error_handling_2();
		func_chooser();
	}
	else if(strcmp(functions, "driehoek")==0)
	{
		fill=0;
		while(fl_token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(triangle_args.function,fl_token);
					break;
				case 1:
					strcpy(triangle_args.x1,fl_token);
					break;
				case 2:
					strcpy(triangle_args.y1,fl_token);
					break;
				case 3:
					strcpy(triangle_args.x2,fl_token);
					break;
				case 4:
					strcpy(triangle_args.y2,fl_token);
					break;
				case 5:
					strcpy(triangle_args.xtop,fl_token);
					break;
				case 6:
					strcpy(triangle_args.ytop,fl_token);
					break;
				case 7:
					strcpy(triangle_args.color,fl_token);
					break;
			}
			fill++;
			fl_token = strtok (NULL, ",");
		}
		if(fill<LEN_TRIANGLE_ARG)
			UART_puts("ERROR 3: to few arguments were given\r");
		else if(fill>LEN_TRIANGLE_ARG)
			UART_puts("ERROR 4: to many arguments were given\r");
		error_handling_2();
		func_chooser();
	}
	else if(strcmp(functions, "tekst")==0)
	{
		fill=0;
		while(fl_token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(text_args.function,fl_token);
					break;
				case 1:
					strcpy(text_args.x1,fl_token);
					break;
				case 2:
					strcpy(text_args.y1,fl_token);
					break;
				case 3:
					strcpy(text_args.text_in,fl_token);
					break;
				case 4:
					strcpy(text_args.color,fl_token);
					break;

			}
			fill++;
			fl_token = strtok (NULL, ",");
		}
		if(fill<LEN_TEXT_ARG)
			UART_puts("ERROR 3: to few arguments were given\r");
		else if(fill>LEN_TEXT_ARG)
			UART_puts("ERROR 4: to many arguments were given\r");
		error_handling_2();
		func_chooser();
	}
	else if(strcmp(functions, "bitmap")==0)
	{
		fill=0;
		while(fl_token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(bitmap_args.function,fl_token);
					break;
				case 1:
					strcpy(bitmap_args.bitmap_nr,fl_token);
					break;
				case 2:
					strcpy(bitmap_args.x1,fl_token);
					break;
				case 3:
					strcpy(bitmap_args.y1,fl_token);
					break;
			}
			fill++;
			fl_token = strtok (NULL, ",");
		}
		if(fill<LEN_BITMAP_ARG)
			UART_puts("ERROR 3: to few arguments were given\r");
		else if(fill>LEN_BITMAP_ARG)
			UART_puts("ERROR 4: to many arguments were given\r");
		error_handling_2();
		func_chooser();
	}
	else if(strcmp(functions, "wacht")==0)
	{
		fill=0;
		while(fl_token != NULL)
		{
			switch(fill)
			{
			case 0:
				strcpy(wait_args.function,fl_token);
				break;
			case 1:
				strcpy(wait_args.time_ms,fl_token);
				break;
			}
			fill++;
			fl_token = strtok (NULL, ",");
		}
		if(fill<LEN_WAIT_ARG)
			UART_puts("ERROR 3: to few arguments were given\r");
		else if(fill>LEN_WAIT_ARG)
			UART_puts("ERROR 4: to many arguments were given\r");
		error_handling_2();
		func_chooser();
	}
}

void error_handling_1()
{
	// functie controle
	if(	strcmp(fl_token,"clearscherm")!=0 && strcmp(fl_token,"lijn")!=0 && strcmp(fl_token,"ellips")!=0 && strcmp(fl_token,"rechthoek")!=0 &&
		strcmp(fl_token,"driehoek")!=0 && strcmp(fl_token,"tekst")!=0 && strcmp(fl_token,"bitmap")!=0 && strcmp(fl_token,"wacht")!=0)
			UART_puts("ERROR 1: wrong typed function\r");
}

void error_handling_2()
{
	// out of range checker
	if(!strcmp(line_args.function,"lijn"))
	{
		if(atoi(line_args.x1) < 0 || atoi(line_args.x1) > 320) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(line_args.y1) < 0 || atoi(line_args.y1) > 240) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(line_args.x2) < 0 || atoi(line_args.x2) > 320) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(line_args.y2) < 0 || atoi(line_args.y2) > 240) UART_puts("ERROR 2: pixel out of range\r");
	}
	else if(!strcmp(ellips_args.function,"ellips"))
	{
		if(atoi(ellips_args.x_center) < 0 || atoi(ellips_args.x_center) > 320) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(ellips_args.y_center) < 0 || atoi(ellips_args.y_center) > 240) UART_puts("ERROR 2: pixel out of range\r");
		else if((atoi(ellips_args.x_center) - atoi(ellips_args.x_rad)) < 0 || (atoi(ellips_args.x_center) + atoi(ellips_args.x_rad)) > 320) UART_puts("ERROR 2: pixel out of range\r");
		else if((atoi(ellips_args.y_center) - atoi(ellips_args.y_rad)) < 0 || (atoi(ellips_args.y_center) + atoi(ellips_args.y_rad)) > 240) UART_puts("ERROR 2: pixel out of range\r");
	}
	else if(!strcmp(rectangle_args.function,"rechthoek"))
	{
		if(atoi(rectangle_args.x1) < 0 || atoi(rectangle_args.x1) > 320) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(rectangle_args.y1) < 0 || atoi(rectangle_args.y1) > 240) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(rectangle_args.x2) < 0 || atoi(rectangle_args.x2) > 320) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(rectangle_args.y2) < 0 || atoi(rectangle_args.y2) > 240) UART_puts("ERROR 2: pixel out of range\r");
	}
	else if(!strcmp(triangle_args.function,"driehoek"))
	{
		if(atoi(triangle_args.x1) < 0 || atoi(triangle_args.x1) > 320) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(triangle_args.y1) < 0 || atoi(triangle_args.y1) > 240) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(triangle_args.x2) < 0 || atoi(triangle_args.x2) > 320) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(triangle_args.y2) < 0 || atoi(triangle_args.y2) > 240) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(triangle_args.xtop) < 0 || atoi(triangle_args.xtop) > 320) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(triangle_args.ytop) < 0 || atoi(triangle_args.ytop) > 240) UART_puts("ERROR 2: pixel out of range\r");
	}
	else if(!strcmp(text_args.function,"tekst"))
	{
		if(atoi(text_args.x1) < 0 || atoi(text_args.x1) > 320) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(text_args.y2) < 0 || atoi(text_args.y2) > 240) UART_puts("ERROR 2: pixel out of range\r");
	}
	else if(!strcmp(bitmap_args.function,"bitmap"))
	{
		if(atoi(bitmap_args.x1) < 0 || atoi(bitmap_args.x1) > 320) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(bitmap_args.y1) < 0 || atoi(bitmap_args.y1) > 240) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(bitmap_args.x1)+40 > 320) UART_puts("ERROR 2: pixel out of range\r");
		else if(atoi(bitmap_args.y1)+40 > 240) UART_puts("ERROR 2: pixel out of range\r");
	}
}
