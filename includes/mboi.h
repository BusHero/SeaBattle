#ifndef __MBOI_H__
# define __MBOI_H__

# include <conio.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <windows.h>
# include <malloc.h>
typedef struct	s_color
{
    BYTE	text; 
    BYTE	background;
}				color;
typedef struct	s_cimp
{
	BYTE	a;
	BYTE	*link;
}				cimp;
typedef struct	s_player
{
	char	NP[21];
	BYTE	punctaj;
}				player;
typedef struct	_item{
	COORD	cor;
	char	*s;
}				item;
typedef struct	_car_cor{
	BYTE	nr_patr;
	BYTE	nr_cor;
}				car_cor;
typedef struct	_car_patr_1{
	BYTE	dim;
	BYTE	m_patr;
	BYTE	nr_cor;
	car_cor *cor;
}				car_patr;
typedef struct	_cimp_efc{
	color	col1;//culoarea cimp 1 
	color	col2;//culoarea cimp  2
	color	col3;//culoarea corabie intreaga
	color	col4;//culoarea corabie ranita
	color	col5;//culoarea corabie distrusa
	color	col6;//culoarea cimp gol
	BYTE	rama;
}				cimp_efc;
color		active;
color		inactive;

void			GotoXY(WORD, WORD);
void			showCursor(BOOL);
color 			GetConsoleColor(BYTE);
void			SetColor(BYTE, BYTE);
void			_cls(BYTE,BYTE,BYTE,BYTE,BYTE);
char			*bfr(BYTE, BYTE, BYTE, BYTE);
void			GotoXY(WORD, WORD);
void			showCursor(BOOL);
color 			GetConsoleColor(BYTE);
void			SetColor(BYTE, BYTE);
void			_cls(BYTE,BYTE,BYTE,BYTE,BYTE);
char			*bfr(BYTE, BYTE, BYTE, BYTE);
void			game(car_patr,cimp_efc);
BYTE			schimb_item_menu(item*,BOOL);
void			set_item_menu();
BYTE			schimb_set_menu(car_patr*,BYTE,BYTE);
void			set_cimp_menu(car_patr*,color,color,color,BYTE);
void			set_intr_cimp_menu(cimp_efc*);
void			write_player(BYTE,BYTE);
void			read_player();
void			reguli(cimp_efc);
void			col_cel(BYTE, BYTE, BYTE, BYTE);
void			intr_cord(int, int, int, int, BYTE);
void			rama(int, int, int, int, BYTE);
void			col_init(int, int, int, int, BYTE, BYTE, BYTE);
void			init_cimp(int, int, int, BYTE, BYTE, BYTE, BYTE);

#endif