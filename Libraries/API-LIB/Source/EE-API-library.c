/*
 * EE-API-library.c
 *
 *  Created on: 28 mei 2018
 *      Author: Milan Dammingh
 */

#include "EE-API-library.h"

/*
 * clearscreen
 */
void clr_screen(uint8_t color)
{
	UB_VGA_FillScreen(color);	// Fill screen
}

/*
 * draw_line
 */
void draw_line(int x1, int y1, int x2, int y2, int tn, int color)
{

	int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;
	uint8_t stn,tn_draw;

	dx=x2-x1;      /* the horizontal distance of the line */
	dy=y2-y1;      /* the vertical distance of the line */
	dxabs=abs(dx);
	dyabs=abs(dy);
	sdx=sgn(dx);
	sdy=sgn(dy);
	x=dyabs>>1;
	y=dxabs>>1;
	px=x1;
	py=y1;

	stn = ((tn%2)==0)? 1:0;  /* even of oneven lijndikte */
	tn_draw = tn>>1;

	if (dxabs>=dyabs) 	/* the line is more horizontal than vertical */
	{
		if(stn==1) /* even line thickness */
		{
			px=x1;
			py=y1;
			for(i=0;i<=dxabs;i++)								/* for loop van 0 tot en met het verschil van de pixels */
			{
				y+=dyabs;										/* adding dyabs for drawing vertical pixel */
				if (y>=dxabs)									/* y is higher than the dxabs of line, so py counting -1/0/1 */
				{
					y-=dxabs;									/* substracting dxabs of y so counting is reset */
					py+=sdy;
				}
				for(int k=-tn_draw;k<tn_draw;k++)
				{
					if(px>=0 && px <= 320 && py>=0 && py <= 240)	/* pixels inside range VGA screen will be drawn */
					{
						UB_VGA_SetPixel(px+k,py-k,color);
						UB_VGA_SetPixel(px+k,py-k-1,color);
					}
				}
				px+=sdx; 										/* -1/0/1 counting pixel */
			}
		}
		else if(stn==0)	/* odd line thickness */
		{
			px=x1;
			py=y1;
			for(i=0;i<=dxabs;i++)								/* for loop van 0 tot en met het verschil van de pixels */
			{
				y+=dyabs;										/* adding dyabs for drawing vertical pixel */
				if (y>=dxabs)									/* y is higher than the dxabs of line, so py counting -1/0/1 */
				{
					y-=dxabs;									/* substracting dxabs of y so counting is reset */
					py+=sdy;
				}
				for(int h=0-tn_draw;h<=tn_draw;h++)
				{
					if(px>=0 && px <= 320 && py>=0 && py <= 240)	/* pixels inside range VGA screen will be drawn */
					{
						UB_VGA_SetPixel(px+h,py-h,color);
						UB_VGA_SetPixel(px+h,py-h-1,color);
					}
				}
				px+=sdx; 										/* -1/0/1 counting pixel */
			}
		}
	}

	else	/* the line is more vertical than horizontal */
	{
		if(stn==1) /* even line thickness */
		{
			px=x1;
			py=y1;
			for(i=0;i<=dxabs;i++)								/* for loop van 0 tot en met het verschil van de pixels */
			{
				y+=dyabs;										/* adding dyabs for drawing vertical pixel */
				if (y>=dxabs)									/* y is higher than the dxabs of line, so py counting -1/0/1 */
				{
					y-=dxabs;									/* substracting dxabs of y so counting is reset */
					py+=sdy;
				}
				for(int k=0-tn_draw;k<tn_draw;k++)
				{
					if(px>=0 && px <= 320 && py>=0 && py <= 240)	/* pixels inside range VGA screen will be drawn */
					{
						UB_VGA_SetPixel(px+k,py-k,color);
						UB_VGA_SetPixel(px+k,py-k-1,color);
					}
				}
				px+=sdx; 										/* -1/0/1 counting pixel */
			}
		}
		else if(stn==0)	/* odd line thickness */
		{
			px=x1;
			py=y1;
			for(i=0;i<=dyabs;i++)								/* for loop van 0 tot en met het verschil van de pixels */
			{
				x+=dxabs;										/* adding dyabs for drawing vertical pixel */
				if (x>=dyabs)									/* y is higher than the dxabs of line, so py counting -1/0/1 */
				{
					x-=dyabs;									/* substracting dxabs of y so counting is reset */
					px+=sdx;
				}
				for(int h=0-tn_draw;h<=tn_draw;h++)
				{
					if(px>=0 && px <= 320 && py>=0 && py <= 240)	/* pixels inside range VGA screen will be drawn */
					{
						UB_VGA_SetPixel(px+h,py-h,color);
						UB_VGA_SetPixel(px+h,py-h-1,color);
					}
				}
				py+=sdy; 										/* -1/0/1 counting pixel */
			}
		}
	}
}

/*
 * draw ellips
 */
void draw_ellips (int x_center,int y_center, int x_rad, int y_rad, int color)
{
	for(int y=-y_rad; y<=y_rad; y++) {
	    for(int x=-x_rad; x<=x_rad; x++) {
	        if(x*x*y_rad*y_rad+y*y*x_rad*x_rad <= y_rad*y_rad*x_rad*x_rad)
	        	UB_VGA_SetPixel(x_center+x,y_center+y,color);
	    }
	}
}

/*
 * draw rectangle
 */
void draw_rectangle (int x1, int y1, int x2, int y2, int color)
{
	for(int i=y1;i<=y2;i++)
	{
		for(int j=x1;j<=x2;j++)
			UB_VGA_SetPixel(j,i,color);
	}
}

/*
 * draw triangle
 */
void draw_triangle(int x1,int y1,int x2,int y2,int xtop,int ytop, int color)
{
	draw_line(x1,y1,x2,y2,1,color);
	draw_line(x1,y1,xtop,ytop,1,color);
	draw_line(xtop,ytop,x2,y2,1,color);
}

/*
 * draw text
 */
void draw_text (int x, int y, char text[], int backcolor, int textcolor) { //functie voor het schrijven van tekst

	for(int i=0;i<strlen(text);i++) //uit de "text" string individuele letters en kleuren halen
	{
		letter_select(x,y,text[i], backcolor, textcolor);
		x = x + 5;
	}
}

/*
 * letter select
 */
void letter_select(int x, int y, char letter, int backcolor, int textcolor)
{
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
		backcolor, textcolor, backcolor, 	//....
		backcolor, textcolor, backcolor, 	//....
		backcolor, textcolor, backcolor, 	//....
		backcolor, textcolor, backcolor, 	//....
		backcolor, backcolor, backcolor, 	//....
		backcolor, backcolor, backcolor, 	//....
	};

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
}

/*
 * bitmap
 */
void draw_bitmap (int bitmap_selector, int x, int y, int backcolor) {
/*
	int yoshi_happy [40][40] = {
	backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x04,0x14,0x34,0x28,0x28,0x34,0x34,0x04,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x08,0x14,0x14,0xff,0xff,0xff,0xff,0xff,0x34,0x08,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x08,0x55,0xff,0xff,0x49,0x6d,0xff,backcolor,0xdb,0x6d,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xa4,0xe4,0xe4,0xe4,0x20,0x92,0xff,0xff,0xff,0x49,0x6d,0xff,backcolor,0xdb,0x6d,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x80,0xe4,0xc4,backcolor,backcolor,0x92,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x6d,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x14,0x14,0x14,0x14,0xff,0xff,0xff,0x9a,0x34,0xff,0x24,0x08,0x14,0x14,0x14,0x04,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xc4,0x40,0x04,0x10,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x10,0x14,0x14,0x14,0x14,0x10,0x08,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x20,0xc4,0xe4,0x40,0x04,0x14,0x14,0x14,0x79,0xff,0xff,0xff,0x55,0x14,0x14,0x14,0x14,0x14,0x10,0x04,0x14,0x08,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x20,0xe4,0xe4,0x40,0x04,0x14,0x14,0xbe,0xff,0xff,0xff,0xff,0x59,0x14,0x14,0x14,0x14,0x14,0x10,0x0c,0x14,0x10,0x0c,0x0c,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x20,0x20,backcolor,0x04,0x14,0x14,0xdf,0xff,0xff,0xff,0xff,0x59,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x10,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x04,0x14,0x14,0xdf,0xff,0xff,0xff,0xff,0x4d,0x0c,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x10,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x60,0x64,0x04,0x14,0x34,0xbe,0xff,0xff,0x49,backcolor,0x08,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x10,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x20,0x20,backcolor,0x04,0x10,0x9a,0xff,0xff,0xb6,0x24,0x08,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x10,0x08,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x20,0x80,backcolor,0x10,0x34,0x9a,0xff,0xff,0xb6,0x4d,0x08,0x14,0x14,0x14,0x14,0x14,0x08,0x08,0x04,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x20,0x40,backcolor,0x10,0x14,0x34,0xff,0xff,0xb6,0x49,backcolor,0x08,0x08,0x08,0x08,0x08,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x80,0x92,0x24,backcolor,backcolor,backcolor,0x10,0x14,0x34,0xff,0xff,0x49,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x20,0x80,0xe4,0x8d,0x24,backcolor,0x08,0x08,0x10,0x55,0x9a,0xff,0xff,0x49,0x24,0x6d,0x08,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x49,0x68,0x80,0x80,0x08,0x08,0x0c,0x14,0x14,0x0c,0x96,0xff,0xff,0xff,0x49,0x24,0x92,0x75,0x0c,0x04,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x08,0x08,0x71,0x49,backcolor,0x08,0x14,0x14,0x14,0x10,0x0c,0x4d,0xb6,0xff,0xff,0xff,0x49,backcolor,backcolor,0x92,0x14,0x08,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,0x28,0x59,0x14,0x04,0x04,0x08,0x14,0x14,0x14,0x14,0x10,0x04,0x92,0xdb,0xff,0xff,0xff,0x49,backcolor,backcolor,0x04,0x10,0x08,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,0x6d,0xff,0x59,0x04,0x08,0x14,0x14,0x14,0x14,0x14,0x14,0x0c,backcolor,0x92,0xff,0xff,0xff,0x49,backcolor,0x08,0x14,0x14,0x08,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,0x24,0xb6,0xff,0x24,0x08,0x14,0x14,0x14,0x14,0x14,0x10,0x04,backcolor,0x92,0xff,0xff,0xff,0x49,0x08,0x14,0x14,0x14,0x08,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xff,0x6d,0x08,0x10,0x14,0x14,0x14,0x14,0x14,0x0c,0x28,0xb6,0xff,0xff,0xff,0x49,0x04,0x0c,0x0c,0x0c,0x04,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xdb,0xdb,0x6d,backcolor,0x10,0x10,0x10,0x10,0x0c,0x24,0xdb,0xff,0xff,0xdb,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0x20,0x20,0x20,0x20,backcolor,backcolor,0x24,0xff,0xdb,0xdb,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xc4,0xe4,0xe4,0xe4,0xe4,0x20,0x6d,0xff,0xff,0x20,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xc4,0xe4,0xe4,0xe4,0xe8,0x20,backcolor,backcolor,backcolor,0xe4,0x40,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xe4,0xe4,0xe4,0xe4,0xe8,0xff,0xe8,0x60,0x20,0xe4,0xe4,0xe4,0xec,0xff,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xe4,0xe4,0xe4,0xe4,0xe4,0xe4,0xe4,0x60,0x20,0xe4,0xe4,0xe4,0xe4,0xe4,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	};

int boo_sad [40][40] = {
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdb,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xdb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x92,0x8d,0x8d,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0x8d,0x8d,0x92,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x20,0x00,0x00,0x44,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x44,0x00,0x00,0x20,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8d,0x69,0xb6,0xb6,0xb6,0xb6,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xb6,0xb6,0xb6,0xb6,0x69,0x8d,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x44,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x44,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8d,0x44,0xb6,0xdb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdb,0xb6,0x44,0x8d,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x69,0x00,0xdb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdb,0x00,0x69,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x92,0x20,0xb6,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x6d,0x20,0xdb,0xff,0x24,0x24,0xff,0xdb,0x00,0x69,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xb6,0x6d,0x20,0xb6,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x69,0x00,0xdb,0xff,0x20,0x20,0xff,0xdb,0x20,0x6d,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0x92,0x00,0x92,0xff,0xff,0xff,0x44,0x00,0x24,0x24,0x24,0x49,0xff,0xff,0xff,0xff,0xff,0xff,0x69,0x00,0xdb,0xff,0x20,0x20,0xff,0xff,0xff,0xb6,0x00,0x8d,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0x92,0x00,0x92,0xff,0xff,0xff,0x44,0x00,0xdb,0xdb,0xdb,0xb6,0x49,0xff,0xff,0xff,0xff,0xff,0x69,0x00,0xdb,0xff,0x20,0x20,0xff,0xff,0xff,0xb6,0x00,0x8d,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xb6,0x49,0x92,0xb6,0xff,0xff,0x44,0x00,0xff,0xff,0xff,0xdb,0x6d,0xff,0xff,0xff,0xff,0xff,0x92,0x49,0xdb,0xff,0x49,0x49,0xff,0xff,0xff,0xb6,0x00,0x8d,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8d,0x00,0xb6,0xff,0x44,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xb6,0x00,0x8d,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xdb,0x92,0x92,0x6d,0xdb,0xff,0x92,0x6d,0x92,0xb6,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xf6,0xfb,0xff,0xf6,0xf6,0xff,0xff,0xf6,0xf6,0xff,0xb6,0x00,0x8d,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0x92,0x00,0x92,0xff,0xff,0xff,0xff,0xff,0x20,0x20,0xff,0xff,0xff,0xff,0xff,0xff,0xf2,0xe0,0xf6,0xff,0xe9,0xe0,0xff,0xff,0xe0,0xe9,0xff,0xb6,0x00,0x8d,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0x92,0x00,0x92,0xff,0xff,0xff,0xff,0xff,0x92,0x92,0xff,0xff,0xff,0xff,0xff,0xff,0xf2,0xe0,0xed,0xf2,0xe4,0xe0,0xee,0xee,0xe0,0xe9,0xff,0xb6,0x00,0x8d,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0x92,0x00,0x92,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf2,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe9,0xff,0xb6,0x00,0x8d,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0x92,0x00,0x92,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf2,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe9,0xff,0xb6,0x00,0x8d,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0x92,0x00,0x92,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf2,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe9,0xff,0xb6,0x00,0x8d,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0x92,0x00,0x92,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf6,0xe9,0xe4,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe4,0xfb,0xd6,0x44,0x6d,0xdb,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0x92,0x00,0x92,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf6,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe4,0xff,0xdb,0x00,0x69,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8d,0x20,0xb6,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf6,0xe0,0xf2,0xff,0xed,0xe0,0xfb,0xff,0xe4,0xe4,0xff,0xdb,0x00,0x69,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x92,0x20,0xb6,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf6,0xe4,0xf2,0xff,0xed,0xe4,0xfb,0xff,0xe4,0xe4,0xff,0xdb,0x20,0x6d,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x69,0x00,0xdb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x44,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8d,0x44,0xb6,0xdb,0xdb,0xdb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdb,0xdb,0xdb,0xdb,0x44,0x6d,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x44,0x00,0x00,0x49,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x44,0x00,0x00,0x20,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8d,0x69,0x69,0x6d,0xb6,0xb6,0xb6,0xb6,0xb6,0xb6,0xb6,0xb6,0xb6,0xb6,0x6d,0x69,0x69,0x6d,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x92,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xdb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xb6,0x8d,0x8d,0x8d,0x8d,0x8d,0x8d,0x8d,0x8d,0x8d,0x8d,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	};

int arrow_down [40][40] = {
	backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xdb,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xdb,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xdb,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xdb,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xdb,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xdb,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	};
int arrow_up [40][40] = {
	backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xdb,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xdb,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xdb,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xdb,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xdb,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xdb,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	};

int arrow_right [40][40] = {
	 backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xdb,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xdb,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor
	,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor
	,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6
	,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6
	,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor
	,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor
	,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xb6,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xdb,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xE0,0xE0,0xdb,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xE0,0xE0,0xdb,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xE0,0xdb,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	};

int arrow_left [40][40] = {
	backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xdb,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xdb,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xdb,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
	,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
	,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
	,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
	,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
	,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
	,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xb6,0xE0,0xE0,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xdb,0xE0,0xE0,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,0xdb,0xE0,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor,backcolor
	};

	if (bitmap_selector == 0)	//YOSHI HAPPY setpixel funtion
	{
		for (int i=0; i<40; i++)
		{
			for (int j=0; j<40; j++)
			{
				int x_pos = j + x;
				int y_pos = i + y;
				UB_VGA_SetPixel(x_pos, y_pos, yoshi_happy[i][j]);
			}
		}
	}
	else if (bitmap_selector==1)	//BOO SAD setpixel function
	{
		for (int i=0; i<40; i++)
		{
			for (int j=0; j<40; j++)
			{
				int x_pos = j + x;
				int y_pos = i + y;
				UB_VGA_SetPixel(x_pos, y_pos, boo_sad[i][j]);
			}
		}
	}
	else if (bitmap_selector==2)		//ARROW UP setpixel function
	{
		for (int i=0; i<40; i++)
		{
			for (int j=0; j<40; j++)
			{
				int x_pos = j + x;
				int y_pos = i + y;
				UB_VGA_SetPixel(x_pos, y_pos, arrow_up[i][j]);
			}
		}
	}
	else if (bitmap_selector==3)	//ARROW DOWN setpixel function
	{
		for (int i=0; i<40; i++)
		{
			for (int j=0; j<40; j++)
			{
				int x_pos = j + x;
				int y_pos = i + y;
				UB_VGA_SetPixel(x_pos, y_pos, arrow_down[i][j]);
			}
		}
	}
	else if (bitmap_selector==4)		//ARROW RIGHT setpixel function
	{
		for (int i=0; i<40; i++)
		{
			for (int j=0; j<40; j++)
			{
				int x_pos = j + x;
				int y_pos = i + y;
				UB_VGA_SetPixel(x_pos, y_pos, arrow_right[i][j]);
			}
		}
	}
	else if (bitmap_selector==5)		//ARROW LEFT setpixel function
	{
		for (int i=0; i<40; i++)
		{
			for (int j=0; j<40; j++)
			{
				int x_pos = j + x;
				int y_pos = i + y;
				UB_VGA_SetPixel(x_pos, y_pos, arrow_left[i][j]);
			}
		}
	}
*/
}

/*
 * wacht
 */
void wait_ms(int time_ms)
{
	DELAY_ms(time_ms);	// Delay in ms
}
