/*
 * front_layer.h
 *
 *  Created on: 28 mei 2018
 *      Author: Milan Dammingh
 */

#ifndef FRONT_LAYER_H_
#define FRONT_LAYER_H_

#include "includes.h"

char *fl_token;
char func_input[20];
char parameters[100];

void input_uart();
void split_string();
void error_handling();

#endif /* FRONT_LAYER_H_ */
