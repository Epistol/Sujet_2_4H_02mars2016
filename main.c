#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<io.h>


typedef struct enreg_produit { // enregistrement de mon fichier produit
	int numero;
	char libelle[255];
	float prix;
	} produit;


void creation_produit (fichier);
void modification_produit();
void annulation_produit();
void visualisation_produit();






void creation_produit (FILE * fichier) {




	int continuer, visual_ok, position, taille;
	continuer = 0;
	char choix_continue;
	char libelle[255];
	int numero;
	float prix;


	printf ("Voulez-vous visualiser la liste des fichiers ? (O/N) \n");
	visual_ok = getch();

	if (visual_ok == 'O' || visual_ok == 'o') {
			visualisation_produit();
			}
	else {


			while (continuer == 0) {


					fichier =  fopen ("produit.dat", "a+");


					fseek (fichier, 1, SEEK_END);


					printf ("CREATION \n");
					printf ("Numero ");
					scanf ("%d", &numero);
					fprintf (fichier, "%d", numero);

					printf ("\n Libelle : ");
					scanf ("%s", &libelle);
					fprintf (fichier, "%s" , libelle);


					printf ("Voulez-vous continuer ? (O/N) ");

					choix_continue = getch();
					if (choix_continue == 'O' || choix_continue == 'o') {
							continuer = 0;

							}
					else {
							fclose (fichier);
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

	char ligne;
	int sum;


	int numero;
	char libelle[255];
	float prix;





	}








int main() {


	char visual_ok;



	FILE * fichier;





	int choisi;
	choisi = 0;


	while (choisi == 0) {
			printf ("GESTION DES PRODUITS\n\n");
			printf ("1 -> Creation d'un produit \n");
			printf ("2 -> Modification d'un produit\n");
			printf ("3 -> Annulation d'un produit\n");
			printf ("4 -> Visualisation d'un produit\n");
			printf ("\n Choix : ");
			scanf ("%d", &choisi);


			switch (choisi) {

					case 1 :
						creation_produit (fichier);
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
						printf ("Choisissez une option de 1 a 4 avec des chiffres \n");
						choisi = NULL;
						break;


					}

			}





	}

