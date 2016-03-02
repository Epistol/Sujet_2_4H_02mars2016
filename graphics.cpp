/*-----------------------------------------------------------------------------------------------------------------*/
// S�bastien GAGNEUR - BTS IG1
//
// Impl�mentation de l'interface graphics.hpp
// d�fintion des diff�rentes fonctions graphiques
//
// Des amliorations peuvent �tre apport�es
/*-----------------------------------------------------------------------------------------------------------------*/

#include "graphics.hpp"

     static WORD bgcolor = BLACK;
     static WORD fgcolor = WHITE << 4;
     #define STDOUT GetStdHandle(STD_OUTPUT_HANDLE)

     void gotoxy( int x, int y ) // Place le curseur en x,y
     {
     COORD dwCursorPosition = { x-1, y-1 }; // petite modification pour �tre pr�cis
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

     void clrscr ( void ) // efface l'�cran
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

	 void tracewindows (int x, int y, int l, int h) // pour tracer une fen�tre en mode texte
	 {
		 int i; //incr�ment

		 h=h-1; // pour simplification de la boucle
		 l=l-1; // pour simplification de la boucle


		 if (x>=0 && y>=0 && l>=2 && h >=2) // peut �tre am�lior� !!
		 {

			gotoxy(x,y); // positionnement coin sup�rieur gauche
			cout<<(char)218; // coin sup�rieur gauche ASCII dos
			gotoxy(x,y+h);
			cout<<(char)192; // coin inf�rieur gauche ASCII dos
			for (i=1;i<l;i++) // boucle pour tracer les c�t�s horizontaux
			{
				gotoxy(x+i,y);
				cout<<(char)196; // trait horizontaux -
				gotoxy(x+i,y+h);
				cout<<(char)196; // trait horizontaux -
			}
			cout<<(char)217; // coin inf�rieur droit ASCII dos
			gotoxy(x+l,y);
			cout<<(char)191; // coin sup�rieur droit ASCII dos

			for (i=1;i<h;i++) // boucle pour tracer les c�t�s verticaux
			{
				gotoxy(x,y+i);
				cout<<(char)179; // trait verticaux |
				gotoxy(x+l,y+i);
				cout<<(char)179; // trait verticaux |
				for (int j=1; j<l;j++)
				{
					gotoxy(x+j,y+i);
					cout<<" "; // placement des blancs dans la fen�tre, pour �viter de cr�er une proc�dure ou fonction efface
				}
			}
		 }
		else
		{
			cout<<"Range Error"; // si erreur dans les param�tres !
		}

	 }



