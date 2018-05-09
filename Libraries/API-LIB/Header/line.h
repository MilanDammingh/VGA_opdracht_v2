/*
 * Line.h
 *
 *  Created on: 3 mei 2018
 *      Author: Milan Dammingh
 */

#ifndef API_LIB_HEADER_LINE_H_
#define API_LIB_HEADER_LINE_H_

#define sgn(x) ((x<0)?-1:((x>0)?1:0)) /* macro to return the sign of a
                                         number */

typedef unsigned char  byte;

void draw_line(int x1, int y1, int x2, int y2, byte color);

#endif /* API_LIB_HEADER_LINE_H_ */
