#include <stdio.h>
#include <stdlib.h>




struct enreg_produit // enregistrement de mon fichier produit

{

int numero;

char libelle[255];

float prix;

} espacer;
char visual_ok;



void creation_produit(fichier) {




	int continuer;
	continuer = 0;
	char choix_continue;
	int numero;
	char libelle[255];
	float prix;
	int position, taille;


	printf("Voulez-vous visualiser la liste des fichiers ? (O/N) \n");
	visual_ok = getch();
	if (visual_ok == 'O' || visual_ok == 'o') {
			visualisation_produit();
			}
	else {


			while (continuer == 0) {


fichier =  fopen("produit.dat","w");


					printf("CREATION \n");
					printf("Numero ");
					scanf("%d", &numero);
					fputs(numero, &fichier);

					printf("\n Libelle : ");
					scanf("%s", libelle);
					fputs(libelle, fichier);


					printf("Voulez-vous continuer ? (O/N) ");

					choix_continue = getch();
					if (choix_continue == 'O' || choix_continue == 'o') {
							continuer = 0;

							}
					else {
							fclose(fichier);
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



void choix(fichier) {

	int choisi;
	choisi = 0;


	while (choisi == 0) {
			printf("GESTION DES PRODUITS\n\n");
			printf("1 -> Creation d'un produit \n");
			printf("2 -> Modification d'un produit\n");
			printf("3 -> Annulation d'un produit\n");
			printf("4 -> Visualisation d'un produit\n");
			printf("\n Choix : ");
			scanf("%d", &choisi);


			switch (choisi) {

					case 1 :
						creation_produit(fichier);
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



			choix(fichier);

	}

