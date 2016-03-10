#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <windows.h> // bibliothÀque contenant des routines sur l'affichage windows.
#include <conio.h>

#include <stdlib.h>





enum CURSOR { // type de curseurs disponibles
	NORMALCURSOR = 0,
	NOCURSOR = 100,
	SOLIDCURSOR = 20,
	};
enum COLORS { // type de couleurs disponibles á l'affichage
	BLACK = 0,
	BLUE = FOREGROUND_BLUE,
	GREEN = FOREGROUND_GREEN,
	CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
	RED = FOREGROUND_RED,
	MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
	BROWN = FOREGROUND_RED | FOREGROUND_GREEN,
	LIGHTGRAY = FOREGROUND_RED | FOREGROUND_GREEN |
	            FOREGROUND_BLUE,
	DARKGRAY = FOREGROUND_INTENSITY,
	LIGHTBLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	LIGHTGREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	LIGHTCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE |
	            FOREGROUND_INTENSITY,
	LIGHTRED = FOREGROUND_RED | FOREGROUND_INTENSITY,
	LIGHTMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE |
	               FOREGROUND_INTENSITY,
	YELLOW = FOREGROUND_RED | FOREGROUND_GREEN |
	         FOREGROUND_INTENSITY,
	WHITE = FOREGROUND_RED | FOREGROUND_GREEN |
	        FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	};



void clrscr ( void ); // prototype de l'effacement de tout l'»cran
void textbackground ( int newcolor ); // Prototype de couleur du fond d'»cran
void textcolor ( int newcolor ); // prototype de couleur du texte
void setcursortype ( int cur ); // prototype du type de curseur á l'»cran
void gotoxy ( int x, int y ); // prototype de placement du curseur coordonn»es x et y
int wherex ( void ); // prototype de coordonn»es x du curseur
int wherey ( void ); // prototype de coordonn»es y du curseur
void tracewindows (int x, int y, int l, int h); // trace une fenÕtre á l'»cran position x (abs) y (ord) l (longueur) h (hauteur) dimensions en caractÀres !

#endif


