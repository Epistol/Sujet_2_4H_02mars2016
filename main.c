#include <stdio.h>
#include <stdlib.h>




struct enreg_produit espacer;
char visual_ok;



void creation_produit() {

	int continuer;
	continuer = 0;
	char choix_continue;
	int numero;
	char libelle[255];
	float prix;
	int position, taille;


	printf("Voulez-vous visualiser la liste des fichiers ? (O/N)");
	visual_ok = getch();
	if (visual_ok == 'O' || visual_ok == 'o') {
			visualisation_produit();
			}
	else {


			while (continuer == 0) {





					printf("CREATION \n");
					printf("Numero ");
					numero = getch();


					printf("Libelle : ");
					scanf("%s", &libelle);
					fputs(libelle, fichier);


					printf("Voulez-vous continuer ? (O/N) ");

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





	}



void choix() {

	int choisi = NULL;

	while (choisi == NULL) {
			printf("GESTION DES PRODUITS");
			printf("1 -> Creation d'un produit");
			printf("2 -> Modification d'un produit");
			printf("3 -> Annulation d'un produit");
			printf("4 -> Visualisation d'un produit");
			printf("\n Choix : ";
			choisi = getch();


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
						printf("Choisissez une option de 1 a 4 avec des chiffres \n");
						choisi = NULL;
						break;


					}

			}


	}



int main() {

    FILE* fichier = NULL;

fichier =  fopen("produit.dat","r+");

			choix();

	}

