/*
 * front_layer.c
 *
 *  Created on: 28 mei 2018
 *      Author: Milan Dammingh
 */
#include "front_layer.h"

void input_uart()
{
	UART_gets(parameters,TRUE);		// Get data from terminal
	fl_token = strtok (parameters,",");	// Put first argument in fl_token
	strcpy(func_input,fl_token);

	split_string(parameters);
}

void split_string()
{
	int fill;
	ll_token = strtok (parameters,",");	// Put first argument in ll_token
	strcpy(functions,ll_token);			// String compare to functions

	if(strcmp(functions, "clearscherm")==0)	// Function is clearscreen
	{
		fill=0;
		while(ll_token != NULL)				// While something in ll_token execute code below
		{
		  switch(fill)						// Fill char string with each parameter
		  {
			case 0:
			  strcpy(clearscrn_args.function,ll_token);
			  break;
			case 1:
			  strcpy(clearscrn_args.color,ll_token);
			  break;
		  }
		  fill++;
		  ll_token = strtok (NULL, ",");
		}
		func_chooser();
	}
	else if(strcmp(functions, "lijn")==0)
	{
		fill=0;
		while(ll_token!= NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(line_args.function,ll_token);
					break;
				case 1:
					strcpy(line_args.x1,ll_token);
					break;
				case 2:
					strcpy(line_args.y1,ll_token);
					break;
				case 3:
					strcpy(line_args.x2,ll_token);
					break;
				case 4:
					strcpy(line_args.y2,ll_token);
					break;
				case 5:
					strcpy(line_args.thickness,ll_token);
					break;
				case 6:
					strcpy(line_args.color,ll_token);
					break;
			}
			fill++;
			ll_token = strtok (NULL, ",");
		}
		func_chooser();
	}
	else if(strcmp(functions, "ellips")==0)
	{
		fill=0;
		while(ll_token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(ellips_args.function,ll_token);
					break;
				case 1:
					strcpy(ellips_args.x_center,ll_token);
					break;
				case 2:
					strcpy(ellips_args.y_center,ll_token);
					break;
				case 3:
					strcpy(ellips_args.x_rad,ll_token);
					break;
				case 4:
					strcpy(ellips_args.y_rad,ll_token);
					break;
				case 5:
					strcpy(ellips_args.color,ll_token);
					break;
			}
			fill++;
			ll_token = strtok (NULL, ",");
		}
		func_chooser();
	}
	else if(strcmp(functions, "rechthoek")==0)
	{
		fill=0;
		while(ll_token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(rectangle_args.function,ll_token);
					break;
				case 1:
					strcpy(rectangle_args.x1,ll_token);
					break;
				case 2:
					strcpy(rectangle_args.y1,ll_token);
					break;
				case 3:
					strcpy(rectangle_args.x2,ll_token);
					break;
				case 4:
					strcpy(rectangle_args.y2,ll_token);
					break;
				case 5:
					strcpy(rectangle_args.color,ll_token);
					break;
			}
			fill++;
			ll_token = strtok (NULL, ",");
		}
		func_chooser();
	}
	else if(strcmp(functions, "driehoek")==0)
	{
		fill=0;
		while(ll_token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(triangle_args.function,ll_token);
					break;
				case 1:
					strcpy(triangle_args.x1,ll_token);
					break;
				case 2:
					strcpy(triangle_args.y1,ll_token);
					break;
				case 3:
					strcpy(triangle_args.x2,ll_token);
					break;
				case 4:
					strcpy(triangle_args.y2,ll_token);
					break;
				case 5:
					strcpy(triangle_args.xtop,ll_token);
					break;
				case 6:
					strcpy(triangle_args.ytop,ll_token);
					break;
				case 7:
					strcpy(triangle_args.color,ll_token);
					break;
			}
			fill++;
			ll_token = strtok (NULL, ",");
		}
		func_chooser();
	}
	else if(strcmp(functions, "tekst")==0)
	{
		fill=0;
		while(ll_token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(text_args.function,ll_token);
					break;
				case 1:
					strcpy(text_args.x1,ll_token);
					break;
				case 2:
					strcpy(text_args.y1,ll_token);
					break;
				case 3:
					strcpy(text_args.text_in,ll_token);
					break;
				case 4:
					strcpy(text_args.color,ll_token);
					break;

			}
			fill++;
			ll_token = strtok (NULL, ",");
		}
		func_chooser();
	}
	else if(strcmp(functions, "bitmap")==0)
	{
		fill=0;
		while(ll_token != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(bitmap_args.function,ll_token);
					break;
				case 1:
					strcpy(bitmap_args.bitmap_nr,ll_token);
					break;
				case 2:
					strcpy(bitmap_args.x1,ll_token);
					break;
				case 3:
					strcpy(bitmap_args.y1,ll_token);
					break;
			}
			fill++;
			ll_token = strtok (NULL, ",");
		}
		func_chooser();
	}
	else if(strcmp(functions, "wacht")==0)
	{
		fill=0;
		while(ll_token != NULL)
		{
			switch(fill)
			{
			case 0:
				strcpy(wait_args.function,ll_token);
				break;
			case 1:
				strcpy(wait_args.time_ms,ll_token);
				break;
			}
			fill++;
			ll_token = strtok (NULL, ",");
		}
		func_chooser();
	}
}

void error_handling()
{
	// functie controle
	if(!strcmp(fl_token,"clearscherm") || !strcmp(fl_token,"lijn") || !strcmp(fl_token,"ellips") || !strcmp(fl_token,"rechthoek") ||
			!strcmp(fl_token,"driehoek") || !strcmp(fl_token,"tekst") || !strcmp(fl_token,"bitmap") || !strcmp(fl_token,"wacht"));
	else
	{
		// Error handling
		UART_puts("ERROR 1: wrong typed function");
	}

	// out of range checker

	if(atoi(line_args.x1) < 0 || atoi(line_args.x1) > 320) UART_puts("ERROR 2: pixel out of range");
	else if(atoi(line_args.y1) < 0 || atoi(line_args.y1) > 240) UART_puts("ERROR 2: pixel out of range");
	else if(atoi(line_args.x2) < 0 || atoi(line_args.x2) > 320) UART_puts("ERROR 2: pixel out of range");
	else if(atoi(line_args.y2) < 0 || atoi(line_args.y2) > 240) UART_puts("ERROR 2: pixel out of range");

	else if(atoi(ellips_args.x_center) < 0 || atoi(ellips_args.x_center) > 320) UART_puts("ERROR 2: pixel out of range");
	else if(atoi(ellips_args.y_center) < 0 || atoi(ellips_args.y_center) > 240) UART_puts("ERROR 2: pixel out of range");

	else if(atoi(rectangle_args.x1) < 0 || atoi(rectangle_args.x1) > 320) UART_puts("ERROR 2: pixel out of range");
	else if(atoi(rectangle_args.y1) < 0 || atoi(rectangle_args.y1) > 240) UART_puts("ERROR 2: pixel out of range");
	else if(atoi(rectangle_args.x2) < 0 || atoi(rectangle_args.x2) > 320) UART_puts("ERROR 2: pixel out of range");
	else if(atoi(rectangle_args.y2) < 0 || atoi(rectangle_args.y2) > 240) UART_puts("ERROR 2: pixel out of range");
	else;



}
