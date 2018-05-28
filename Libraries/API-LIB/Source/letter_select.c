/*
 * letter_select.c
 *
 *  Created on: May 23, 2018
 *      Author: Samuel Benhaiem
 */

#include "letter_select.h"


/*
void letter_select(int x, int y, char letter, int backcolor, int textcolor){

	//____________________________________ALFABET IN C ARRAY_________________________________________

	int letter_A[10][4] = {
			  backcolor, backcolor, backcolor, backcolor, //....
			  backcolor, backcolor, backcolor, backcolor, //....
			  backcolor, textcolor, textcolor, backcolor, //.@@.
			  backcolor, textcolor, textcolor, backcolor, //.@@.
			  textcolor, backcolor, backcolor, textcolor, //@..@
			  textcolor, backcolor, backcolor, textcolor, //@..@
			  textcolor, textcolor, textcolor, textcolor, //@@@@
			  textcolor, backcolor, backcolor, textcolor, //@..@
			  backcolor, backcolor, backcolor, backcolor, //....
			  backcolor, backcolor, backcolor, backcolor
	};
	int letter_B[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, textcolor, textcolor, backcolor,  //@@@.
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, textcolor, textcolor, backcolor,  //@@@.
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, textcolor, textcolor, backcolor,  //@@@.
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_C[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, textcolor, textcolor, textcolor,  //.@@@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, textcolor, textcolor, backcolor,  //.@@.
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_D[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, textcolor, textcolor, backcolor,  //@@@.
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, textcolor, textcolor, backcolor,  //@@@.
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_E[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, textcolor, textcolor, textcolor,  //@@@@
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, textcolor, textcolor, backcolor,  //@@@.
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, textcolor, textcolor, textcolor,  //@@@@
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_F[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, textcolor, textcolor, textcolor,  //@@@@
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, textcolor, textcolor, backcolor,  //@@@.
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_G[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, textcolor, textcolor, textcolor,  //.@@@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, backcolor, textcolor, textcolor,  //@.@@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, textcolor, textcolor, backcolor,  //.@@.
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_H[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, textcolor, textcolor, textcolor,  //@@@@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_I[10][3] = {
			  backcolor, backcolor, backcolor,  //...
			  backcolor, backcolor, backcolor,  //... //PAS OP 3 X WAARDES
			  textcolor, textcolor, textcolor,  //@@@
			  backcolor, textcolor, backcolor,  //.@.
			  backcolor, textcolor, backcolor,  //.@.
			  backcolor, textcolor, backcolor,  //.@.
			  backcolor, textcolor, backcolor,  //.@.
			  textcolor, textcolor, textcolor,  //@@@
			  backcolor, backcolor, backcolor,  //...
			  backcolor, backcolor, backcolor,  //...
	};
	int letter_J[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, textcolor,  //...@
			  backcolor, backcolor, backcolor, textcolor,  //...@
			  backcolor, backcolor, backcolor, textcolor,  //...@
			  backcolor, backcolor, backcolor, textcolor,  //...@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, textcolor, textcolor, backcolor,  //.@@.
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_K[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, textcolor, backcolor,  //@.@.
			  textcolor, textcolor, backcolor, backcolor,  //@@..
			  textcolor, backcolor, textcolor, backcolor,  //@.@.
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_L[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, textcolor, textcolor, textcolor,  //@@@@
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_M[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, textcolor, textcolor, textcolor,  //@@@@
			  textcolor, textcolor, textcolor, textcolor,  //@@@@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_N[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, textcolor, backcolor, textcolor,  //@@.@
			  textcolor, textcolor, backcolor, textcolor,  //@@.@
			  textcolor, backcolor, textcolor, textcolor,  //@.@@
			  textcolor, backcolor, textcolor, textcolor,  //@.@@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_O[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, textcolor, textcolor, backcolor,  //.@@.
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, textcolor, textcolor, backcolor,  //.@@.
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_P[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, textcolor, textcolor, backcolor,  //@@@.
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, textcolor, textcolor, backcolor,  //@@@.
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  textcolor, backcolor, backcolor, backcolor,  //@...
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_Q[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, textcolor, textcolor, backcolor,  //.@@.
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, textcolor, textcolor, backcolor,  //.@@.
			  backcolor, backcolor, textcolor, backcolor,  //..@.
			  backcolor, backcolor, backcolor, textcolor,  //...@
	};
	int letter_R[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, textcolor, textcolor, backcolor,  //@@@.
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, textcolor, textcolor, backcolor,  //@@@.
			  textcolor, backcolor, textcolor, backcolor,  //@.@.
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_S[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, textcolor, textcolor, textcolor,  //.@@@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, textcolor, backcolor, backcolor,  //.@..
			  backcolor, backcolor, textcolor, backcolor,  //..@.
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, textcolor, textcolor, backcolor,  //@@@.
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_T[10][5] = {
			  backcolor, backcolor, backcolor, backcolor, backcolor,  //.....//PAS OP X WAARDE 5
			  backcolor, backcolor, backcolor, backcolor, backcolor,  //.....
			  textcolor, textcolor, textcolor, textcolor, textcolor,  //@@@@@
			  textcolor, backcolor, textcolor, backcolor, textcolor,  //@.@.@
			  backcolor, backcolor, textcolor, backcolor, backcolor,  //..@..
			  backcolor, backcolor, textcolor, backcolor, backcolor,  //..@..
			  backcolor, backcolor, textcolor, backcolor, backcolor,  //..@..
			  backcolor, textcolor, textcolor, textcolor, backcolor,  //.@@@.
			  backcolor, backcolor, backcolor, backcolor, backcolor,  //.....
			  backcolor, backcolor, backcolor, backcolor, backcolor,  //.....
	};
	int letter_U[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, textcolor, textcolor, backcolor,  //.@@.
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_V[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, textcolor, textcolor, backcolor,  //.@@.
			  backcolor, textcolor, textcolor, backcolor,  //.@@.
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_W[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, textcolor, textcolor, textcolor,  //@@@@
			  textcolor, textcolor, textcolor, textcolor,  //@@@@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_X[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, textcolor, textcolor, backcolor,  //.@@.
			  backcolor, textcolor, textcolor, backcolor,  //.@@.
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int letter_Y[10][5] = {
			  backcolor, backcolor, backcolor, backcolor, backcolor,  //.....//pas op x waarde 5
			  backcolor, backcolor, backcolor, backcolor, backcolor,  //.....
			  textcolor, textcolor, backcolor, textcolor, textcolor,  //@@.@@
			  backcolor, textcolor, backcolor, textcolor, backcolor,  //.@.@.
			  backcolor, backcolor, textcolor, backcolor, backcolor,  //..@..
			  backcolor, backcolor, textcolor, backcolor, backcolor,  //..@..
			  backcolor, backcolor, textcolor, backcolor, backcolor,  //..@..
			  backcolor, textcolor, textcolor, textcolor, backcolor,  //.@@@.
			  backcolor, backcolor, backcolor, backcolor, backcolor,  //.....
			  backcolor, backcolor, backcolor, backcolor, backcolor,  //.....
	};
	int letter_Z[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  textcolor, textcolor, textcolor, textcolor,  //@@@@
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  backcolor, backcolor, textcolor, backcolor,  //..@.
			  backcolor, textcolor, backcolor, backcolor,  //.@..
			  textcolor, backcolor, backcolor, textcolor,  //@..@
			  textcolor, textcolor, textcolor, textcolor,  //@@@@
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int spatie[10][4] = {
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor, backcolor,  //....
	};
	int komma[13][3]={
			  backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor,  //....
			  backcolor, backcolor, backcolor,  //....
			  backcolor, textcolor, backcolor, //....
			  backcolor, textcolor, backcolor, //....
			  backcolor, textcolor, backcolor, //....
			  backcolor, textcolor, backcolor, //....
			  backcolor, backcolor, backcolor, //....
			  backcolor, backcolor, backcolor, //....
	};



	//___________________________________SHIFT FUNCTION FOR ITALIC___________________________________







	//____________________________________SWITCH VOOR LETTER KEUZE_________________________________________

	switch (letter)
	{
		case 'a':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_A[i][j]);
				}
			}
			break;
		case 'b':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_B[i][j]);
				}
			}
			break;
		case 'c':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_C[i][j]);
				}
			}
			break;
		case 'd':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_D[i][j]);
				}
			}
			break;
		case 'e':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_E[i][j]);
				}
			}
			break;
		case 'f':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_F[i][j]);
				}
			}
			break;
		case 'g':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_G[i][j]);
				}
			}
			break;
		case 'h':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_H[i][j]);
				}
			}
			break;
		case 'i':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<3; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_I[i][j]);
				}
			}
			break;
		case 'j':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_J[i][j]);
				}
			}
			break;
		case 'k':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_K[i][j]);
				}
			}
			break;
		case 'l':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_L[i][j]);
				}
			}
			break;
		case 'm':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_M[i][j]);
				}
			}
			break;
		case 'n':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_N[i][j]);
				}
			}
			break;


		case 'o':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_O[i][j]);
				}
			}
			break;
		case 'p':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_P[i][j]);
				}
			}
			break;
		case 'q':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_Q[i][j]);
				}
			}
			break;
		case 'r':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_R[i][j]);
				}
			}
			break;

		case 's':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_S[i][j]);
				}
			}
			break;
		case 't':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<5; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_T[i][j]);
				}
			}
			break;
		case 'u':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_U[i][j]);
				}
			}
			break;


		case 'v':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_V[i][j]);
				}
			}
			break;
		case 'w':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_W[i][j]);
				}
			}
			break;

		case 'x':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_X[i][j]);
				}
			}
			break;
		case 'y':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<5; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_Y[i][j]);
				}
			}
			break;


		case 'z':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, letter_Z[i][j]);
				}
			}
			break;
		case ' ':
			for (int i=0; i<10; i++)
			{
				for (int j=0; j<4; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, spatie[i][j]);
				}
			}
			break;
		case ',':
			for (int i=0; i<13; i++)
			{
				for (int j=0; j<3; j++)
				{
					int x_pos = j + x;
					int y_pos = i + y;
					UB_VGA_SetPixel(x_pos, y_pos, komma[i][j]);
				}
			}
			break;

	}
}*/

