/*-------------------------------------------------------------------------
-----------------------------------------*/
//
//
// Interface des focntions graphiques
// auteur : Eric Teetz ( prototypes des fonctions )
// modifications de sebastien gagneur
// bibliothËque de fonctions graphiques
// commentaires de sÈbastien gagneur
// Attention : certaines fonctions comportent encore des erreurs
/*-------------------------------------------------------------------------
------------------------------------------*/
#ifndef ECONIO_H
#define ECONIO_H
#include <windows.h> // bibliothËque contenant des routines sur l'affichage windows.
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;
enum CURSOR { // type de curseurs disponibles
NORMALCURSOR = 0,
NOCURSOR = 100,
SOLIDCURSOR = 20,
};
enum COLORS { // type de couleurs disponibles ‡ l'affichage
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


#ifdef __cplusplus
extern "C" {
#endif
void clrscr( void ); // prototype de l'effacement de tout l'Ècran
void textbackground( int newcolor ); // Prototype de couleur du fond d'Ècran
void textcolor( int newcolor ); // prototype de couleur du texte
void setcursortype( int cur ); // prototype du type de curseur ‡ l'Ècran
void gotoxy( int x, int y ); // prototype de placement du curseur coordonnÈes x et y
int wherex( void ); // prototype de coordonnÈes x du curseur
int wherey( void ); // prototype de coordonnÈes y du curseur
void tracewindows(int x, int y, int l, int h); // trace une fenÍtre ‡ l'Ècran position x (abs) y (ord) l (longueur) h (hauteur) dimensions en caractËres !
#ifdef __cplusplus
}
#endif
#endif
