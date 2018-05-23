/*
 * terminal_input.c
 *
 *  Created on: 22 mei 2018
 *      Author: Milan Dammingh
 */

#include "terminal_input.h"

uint8_t color(char color_input);

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
	char color[20];
};
struct arguments line_args;
struct arguments ellips_args;
struct arguments rectangle_args;


void get_data()
{
	int fill=0;

	UART_gets(parameters,TRUE);
	str_check = strtok (parameters,",");

	strcpy(functions,str_check);

	if(strcmp(functions, "lijn")==0)
	{
		fill=0;
		UART_puts("lijn\r");
		while(str_check != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(functions,str_check);
					break;
				case 1:
					strcpy(line_args.x1,str_check);
					break;
				case 2:
					strcpy(line_args.y1,str_check);
					break;
				case 3:
					strcpy(line_args.x2,str_check);
					break;
				case 4:
					strcpy(line_args.y2,str_check);
					break;
				case 5:
					strcpy(line_args.thickness,str_check);
					break;
				case 6:
					strcpy(line_args.color,str_check);
					break;
			}
			fill++;
			str_check = strtok (NULL, " ,.-");
		}
		draw_line(atoi(line_args.x1),atoi(line_args.y1),atoi(line_args.x2),atoi(line_args.y2),atoi(line_args.thickness),color(line_args.color));
	}
	else if(strcmp(functions, "ellips")==0)
	{
		fill=0;
		UART_puts("ellips\r");
		while(str_check != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(functions,str_check);
					break;
				case 1:
					strcpy(ellips_args.x_center,str_check);
					break;
				case 2:
					strcpy(ellips_args.y_center,str_check);
					break;
				case 3:
					strcpy(ellips_args.x_rad,str_check);
					break;
				case 4:
					strcpy(ellips_args.y_rad,str_check);
					break;
				case 5:
					strcpy(ellips_args.color,str_check);
					break;
			}
			fill++;
			str_check = strtok (NULL, ",");
		}
		draw_ellips(atoi(ellips_args.x_center),atoi(ellips_args.y_center),atoi(ellips_args.x_rad),atoi(ellips_args.y_rad),color(ellips_args.color));
	}
	else if(strcmp(functions, "rechthoek")==0)
	{
		fill=0;
		UART_puts("rechthoek\r");
		while(str_check != NULL)
		{
			switch(fill)
			{
				case 0:
					strcpy(functions,str_check);
					break;
				case 1:
					strcpy(rectangle_args.x1,str_check);
					break;
				case 2:
					strcpy(rectangle_args.y1,str_check);
					break;
				case 3:
					strcpy(rectangle_args.x2,str_check);
					break;
				case 4:
					strcpy(rectangle_args.y2,str_check);
					break;
				case 5:
					strcpy(rectangle_args.color,str_check);
					break;
			}
			fill++;
			str_check = strtok (NULL, ",");
		}
		draw_rectangle(atoi(rectangle_args.x1),atoi(rectangle_args.y1),atoi(rectangle_args.x2),atoi(rectangle_args.y2),color(rectangle_args.color));
	}




//	draw_ellips(atoi(line_args.x_center),atoi(line_args.y_center),atoi(line_args.x_rad),atoi(line_args.y_rad),color(line_args.color));

}

uint8_t color(char color_input)
{
	if(strcmp(line_args.color, "zwart")==0) return zwart;
	else if(strcmp(line_args.color, "blauw\r")==0) return blauw;
	else if(strcmp(line_args.color, "lichtblauw")==0) return lichtblauw;
	else if(strcmp(line_args.color, "groen")==0) return groen;
	else if(strcmp(line_args.color, "groen\r")==0) return groen;
	else if(strcmp(line_args.color, "lichtgroen")==0) return lichtgroen;
	else if(strcmp(line_args.color, "rood")==0) return rood;
	else if(strcmp(line_args.color, "lichtrood")==0) return lichtrood;
	else if(strcmp(line_args.color, "wit")==0) return wit;
	else if(strcmp(line_args.color, "cyaan")==0) return cyaan;
	else if(strcmp(line_args.color, "lichtcyaan")==0) return lichtcyaan;
	else if(strcmp(line_args.color, "magenta")==0) return magenta;
	else if(strcmp(line_args.color, "lichtmagenta")==0) return lichtmagenta;
	else if(strcmp(line_args.color, "geel")==0) return geel;
	else if(strcmp(line_args.color, "bruin")==0) return bruin;
	else if(strcmp(line_args.color, "grijs")==0) return grijs;
	else if(strcmp(line_args.color, "paars")==0) return paars;
	else return wit;
};


/*



	UART_gets(functions,TRUE);

	if(strcmp(functions, "lijn")==0)
	{
		UART_gets(parameters,TRUE);
		str_check = strtok (parameters," ,");


		while (str_check != NULL)
		{
			UART_puts(str_check);
			UART_puts("\t");

			switch(i){
			case 0:
				line_args.x1=str_check;
				break;
			case 1:
				line_args.y1=str_check;
				break;
			case 2:
				line_args.x2=str_check;
				break;
			case 3:
				line_args.y2=str_check;
				break;
			case 4:
				line_args.thickness=str_check;
				break;
			case 5:
				strcpy(line_args.color,str_check);
				break;
			default:
				break;
			}
			i++;
			str_check = strtok (NULL, " ,.-");
		}

//		draw_line(line_args.x1,(int)line_args.y1,(int)line_args.x2,(int)line_args.y2,(int)line_args.thickness,(int)line_args.color);


//
//		UART_puts("color_line = "); UART_putchar(color_line);


	}

	else if(strcmp(functions, "triangle")==0)
	{
		UART_puts("You need to type the following parameter:"
				"x1 y1 x2 y2 x3 y3 color\r");
	}
	else if(strcmp(functions, "rectangle")==0)
	{
		UART_puts("You need to type the following parameter:"
				"x1 y1 x2 y2 color\r");
	}
	else if(strcmp(functions, "ellips")==0)
	{
		UART_puts("You need to type the following parameter:"
				"x_center y_center x_raduis y_radius color\r");
	}
	else if(strcmp(functions, "text")==0)
	{
		UART_puts("You need to type the following parameter:"
				"x1 y1 text font color style\r"
				"style = normal or fat or cursive\r");
	}
	else if(strcmp(functions, "bitmap")==0)
	{
		UART_puts("You need to type the following bitmaps:"
				"\r");
	}
	else if(strcmp(functions, "clr_screen")==0)
	{
		UART_puts("screen_clr_screen\r");
	}

//	else
//		UART_puts("You typed the wrong function, you can choose one of these: line/triangle/rectangle/ellips/text/bitmap/clr_screen\r");



	char * pch;

	pch = strtok (text," ,");
	while (pch != NULL)
	{
//		for(int i=0;i<7;i++)
//			draw[i] = pch;
		UART_puts(pch);
		UART_puts("\t");

		pch = strtok (NULL, " ,.-");
	}


//	for(int j=0;j<7;j++)
//	{
//		UART_puts(draw[j]);
//		UART_puts("\r");
//	}
}
*/
