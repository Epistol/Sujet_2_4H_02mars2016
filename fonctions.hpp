#ifndef FONCTIONS_HPP_INCLUDED
#define FONCTIONS_HPP_INCLUDED

#include <windows.h> // bibliothËque contenant des routines sur l'affichage windows.
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>



void choix();
void creation_produit();
void modification_produit();
void annulation_produit();
void visualisation_produit();
int connaitre_taille();

struct enreg_produit // enregistrement de mon fichier produit

{

int numero;

char libelle[255];

float prix;

};




#endif // FONCTIONS_HPP_INCLUDED
