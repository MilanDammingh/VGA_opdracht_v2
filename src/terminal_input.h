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

char *token;
char functions[20];
char parameters[100];

struct arguments {
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

void get_data(void);

#endif /* TERMINAL_INPUT_H_ */
