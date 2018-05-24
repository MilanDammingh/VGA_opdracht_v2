/*
 * logic_layer.c
 *
 *  Created on: 24 mei 2018
 *      Author: Milan Dammingh
 */
#include "logic_layer.h"

int logic_layer()
{
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
	else if(rectangle_args.function != 0)
	{
		UART_puts("function = "); UART_puts(rectangle_args.function); UART_puts("\r");
	}
	else if(triangle_args.function != 0)
	{
		UART_puts("function = "); UART_puts(triangle_args.function); UART_puts("\r");
	}
	else if(text_args.function != 0)
	{
		UART_puts("function = "); UART_puts(text_args.function); UART_puts("\r");
	}
	else if(bitmap_args.function != 0)
	{
		UART_puts("function = "); UART_puts(bitmap_args.function); UART_puts("\r");
	}
	else if(wait_args.function != 0)
	{
		UART_puts("function = "); UART_puts(wait_args.function); UART_puts("\r");
	}
	else
	{
		// Error handling
		UART_puts("error handling");
	}




}
