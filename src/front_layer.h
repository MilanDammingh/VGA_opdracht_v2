/*
 * front_layer.h
 *
 *  Created on: 28 mei 2018
 *      Author: Milan Dammingh
 */

#ifndef FRONT_LAYER_H_
#define FRONT_LAYER_H_

#include "includes.h"
#include "EE-API-library.h"

#define LEN_CLEARSCRN_ARG		2
#define LEN_LINE_ARG			7
#define LEN_ELLIPS_ARG			6
#define LEN_RECTANGLE_ARG		6
#define LEN_TRIANGLE_ARG		8
#define LEN_TEXT_ARG			6
#define LEN_BITMAP_ARG			4
#define LEN_WAIT_ARG			2



char *fl_token;
char func_input[20];
char parameters[100];

void input_uart();
void error_handling_1();
void error_handling_2();

#endif /* FRONT_LAYER_H_ */
