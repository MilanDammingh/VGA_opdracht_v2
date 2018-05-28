/*******************************************************************************************************
*
* Filename      : includes.h
* Version       : V1.00
* Programmer(s) : Samuel Benhaiem en Milan Dammingh
* 				: COOcox
*
*  07-07-2014 toevoeging van false en true defines
*********************************************************************************************************
*/

#ifndef  INCLUDES_PRESENT
#define  INCLUDES_PRESENT
#define OS_MASTER_FILE
/*
*********************************************************************************************************
*                                         STANDARD LIBRARIES
*********************************************************************************************************
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*
*********************************************************************************************************
*                                              LIBRARIES
*********************************************************************************************************
*/


//#include  "os_cpu.h"
//#include  "os_cfg.h"

/*
*********************************************************************************************************
*                                                 OS
*********************************************************************************************************
*/

//#include  "ucos_ii.h"


#include "misc.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"

/*
*********************************************************************************************************
*                                                 VGA
*********************************************************************************************************
*/

#include "stm32_ub_vga_screen.h"


/*
*********************************************************************************************************
*                                            INCLUDES OPDRACHT
*********************************************************************************************************
*/

#include "EE-API-library.h"

/*
*********************************************************************************************************
*                                            INCLUDES 3 LAYER MODEL
*********************************************************************************************************
*/

#include "logic_layer.h"

/*
*********************************************************************************************************
*                                            INCLUDES DICOVERY BOARD
*********************************************************************************************************
*/
#include "uart.h"
#include "delay.h"
/*
#include "lcd.h"
#include "leds.h"
#include "buzzer.h"
#include "keys.h"
*/

/*
*********************************************************************************************************
*                                            INCLUDES END
*********************************************************************************************************
*/

#define TRUE		1
#define FALSE		0

/*
struct arguments {
	char function[10];
	char x1[5];
	char y1[5];
	char x2[5];
	char y2[5];
	char xtop[5];
	char ytop[5];
	char x_center[5];
	char y_center[5];
	char x_rad[5];
	char y_rad[5];
	char thickness[5];
	char text_in[50];
	char bitmap_nr[5];
	char time_ms[5];
	char color[20];
};

struct arguments clearscrn_args;
struct arguments line_args;
struct arguments ellips_args;
struct arguments rectangle_args;
struct arguments triangle_args;
struct arguments text_args;
struct arguments bitmap_args;
struct arguments wait_args;
*/
#endif

