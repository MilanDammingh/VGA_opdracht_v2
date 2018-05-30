//--------------------------------------------------------------
// File     : main.h
// Datum    : 30.03.2016
// Version  : 1.0
// Autor    : UB
// mods by	: Samuel Benhaiem and Milan Dammingh
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.x
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_core DMA LIB 320x240, 8bit color
//--------------------------------------------------------------

#include "EE-API-library.h"

//#include "includes.h"
#include "EE-API-library.h"
#include "front_layer.h"
#include "logic_layer.h"
#include "IO_layer.h"

#ifndef __STM32F4_UB_MAIN_H
#define __STM32F4_UB_MAIN_H

void UART_init(void);
void DELAY_init(void);

//--------------------------------------------------------------
#endif // __STM32F4_UB_MAIN_H
