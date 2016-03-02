/*-----------------------------------------------------------------------------------------------------------------*/
// Sébastien GAGNEUR - BTS IG1
//
// Implémentation de l'interface graphics.hpp
// défintion des différentes fonctions graphiques
//
// Des amliorations peuvent être apportées
/*-----------------------------------------------------------------------------------------------------------------*/

#include "graphics.hpp"

     static WORD bgcolor = BLACK;
     static WORD fgcolor = WHITE << 4;
     #define STDOUT GetStdHandle(STD_OUTPUT_HANDLE)

     void gotoxy( int x, int y ) // Place le curseur en x,y
     {
     COORD dwCursorPosition = { x-1, y-1 }; // petite modification pour être précis
     SetConsoleCursorPosition (STDOUT, dwCursorPosition);
     }

     int wherex( void ) // Renvoie la valeur de x
     {
     CONSOLE_SCREEN_BUFFER_INFO coninfo;
     GetConsoleScreenBufferInfo (STDOUT, &coninfo);
     return coninfo.dwCursorPosition.X;
     }

     int wherey( void ) // Renvoie la valeur de y
     {
     CONSOLE_SCREEN_BUFFER_INFO coninfo;
     GetConsoleScreenBufferInfo (STDOUT, &coninfo);
     return coninfo.dwCursorPosition.Y;
     }

     void textcolor( int newcolor ) // Change la couleur du texte
     {
     fgcolor = newcolor;
     SetConsoleTextAttribute (STDOUT, fgcolor | bgcolor);
     }

     void textbackground( int newcolor ) // change la couleur du fond
     {
     bgcolor = newcolor << 4;
     SetConsoleTextAttribute (STDOUT, fgcolor | bgcolor);
     }

     void setcursortype( int cur ) // type de curseur
     {
     BOOL visible = cur != NOCURSOR;
     CONSOLE_CURSOR_INFO CursorInfo = { cur, visible };
     SetConsoleCursorInfo (STDOUT, &CursorInfo);
     }

     void clrscr ( void ) // efface l'écran
     {
     HANDLE hstdout = STDOUT;
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if (GetConsoleScreenBufferInfo (hstdout, &csbi))
     {
         COORD coordScreen = { 0, 0 };
         DWORD cCharsWritten;
         DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
         FillConsoleOutputCharacter (hstdout, ' ', dwConSize, coordScreen, &cCharsWritten);
         FillConsoleOutputAttribute (hstdout, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
         SetConsoleCursorPosition    (hstdout, coordScreen);
     }
	 }

	 void tracewindows (int x, int y, int l, int h) // pour tracer une fenêtre en mode texte
	 {
		 int i; //incrément

		 h=h-1; // pour simplification de la boucle
		 l=l-1; // pour simplification de la boucle


		 if (x>=0 && y>=0 && l>=2 && h >=2) // peut être amélioré !!
		 {

			gotoxy(x,y); // positionnement coin supérieur gauche
			cout<<(char)218; // coin supérieur gauche ASCII dos
			gotoxy(x,y+h);
			cout<<(char)192; // coin inférieur gauche ASCII dos
			for (i=1;i<l;i++) // boucle pour tracer les côtés horizontaux
			{
				gotoxy(x+i,y);
				cout<<(char)196; // trait horizontaux -
				gotoxy(x+i,y+h);
				cout<<(char)196; // trait horizontaux -
			}
			cout<<(char)217; // coin inférieur droit ASCII dos
			gotoxy(x+l,y);
			cout<<(char)191; // coin supérieur droit ASCII dos

			for (i=1;i<h;i++) // boucle pour tracer les côtés verticaux
			{
				gotoxy(x,y+i);
				cout<<(char)179; // trait verticaux |
				gotoxy(x+l,y+i);
				cout<<(char)179; // trait verticaux |
				for (int j=1; j<l;j++)
				{
					gotoxy(x+j,y+i);
					cout<<" "; // placement des blancs dans la fenêtre, pour éviter de créer une procédure ou fonction efface
				}
			}
		 }
		else
		{
			cout<<"Range Error"; // si erreur dans les paramètres !
		}

	 }



