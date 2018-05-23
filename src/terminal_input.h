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

char *line, *rectangle, *triangle, *ellips, *text, *bitmap, *str_check;

char functions[20];
char parameters[100];
char draw[7];
char test[100];

//char arguments[][];

void get_data(void);

#endif /* TERMINAL_INPUT_H_ */
