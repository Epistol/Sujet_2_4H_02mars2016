#include <iostream>
#include <fstream>
#include <string>
#include "graphics.hpp"
#include "fonctions.hpp"



using namespace std;

struct enreg_produit espacer;
char visual_ok;


void creation_produit() {

	int continuer;
	continuer = 0;
	char choix_continue;
	int numero;
	char libelle[255];
	float prix;
	int position,taille;


	cout << "Voulez-vous visualiser la liste des fichiers ? (O/N)" << endl;
	cin >> visual_ok;

	if (visual_ok == 'O' || visual_ok == 'o') {
			visualisation_produit();
			}
	else {


			while (continuer == 0) {


					ofstream monFlux ("produit.dat"); //On essaye d'ouvrir le fichier

					position = monFlux.tellp(); //On récupére la position
					cout << "Position : "<< position;
					monFlux.seekp(taille, ios::end);
					position = monFlux.tellp(); //On récupére la position
					cout << "Position : "<< position;
					cout << "CREATION \n" << endl;
					cout << "Numero  ";
					cin >> numero;
					monFlux << numero << " ";

					cout << "Libelle : ";
					cin >> libelle;
					monFlux << libelle << " ";

					cout << "Prix : ";
					cin >> prix;
					monFlux << prix << "\n";

					cout << endl <<  "Voulez-vous continuer ? (O/N) " << endl;

					cin >> choix_continue;
					if (choix_continue == 'O' || choix_continue == 'o') {
							continuer = 0;

							}
					else {
							continuer = 1;
							}
					}


			}


	}

void modification_produit() {

	}
void annulation_produit() {

	}
void visualisation_produit() {

	string ligne;
	int sum;


int numero;
char libelle[255];
float prix;


	ifstream monFlux ("produit.dat"); //On essaye d'ouvrir le fichier

if (monFlux) {
    monFlux.seekg(0, ios::end);  //On se déplace à la fin du fichier

    int taille;
    taille = monFlux.tellg();
    //On récupère la position qui correspond donc a la taille du fichier !

    cout << "Taille du fichier : " << taille << " octets." << endl;

}



}



void choix() {

	int choisi = NULL;

	while (choisi == NULL) {
			cout << "GESTION DES PRODUITS" << endl;
			cout << "1 -> Creation d'un produit" << endl;
			cout << "2 -> Modification d'un produit" << endl;
			cout << "3 -> Annulation d'un produit" << endl;
			cout << "4 -> Visualisation d'un produit" << endl;
			cout << "\n Choix : ";
			cin >> choisi;


			switch (choisi) {

					case 1 :
						creation_produit();
						break;
					case 2 :
						modification_produit();
						break;
					case 3 :
						annulation_produit();
						break;
					case 4 :
						visualisation_produit();
						break;
					default :
						cout << "Choisissez une option de 1 a 4 avec des chiffres \n" << endl;
						choisi = NULL;
						break;


					}

			}


	}



int main() {



	ofstream monFlux ("produit.dat"); //On essaye d'ouvrir le fichier

	if (monFlux) { //On teste si tout est OK
			choix();
			}
	else {
			cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
			}


	}
