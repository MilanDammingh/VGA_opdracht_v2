/*
 * terminal_input.h
 *
 *  Created on: 22 mei 2018
 *      Author: Milan Dammingh
 */

#ifndef TERMINAL_INPUT_H_
#define TERMINAL_INPUT_H_

#include "includes.h"
#include <string.h>

char *str_check;


char functions[20];
char parameters[100];
char draw[7];

int input_line[4];


void get_data(void);

#endif /* TERMINAL_INPUT_H_ */
