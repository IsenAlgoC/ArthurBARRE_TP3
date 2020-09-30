#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include<locale.h>

int main() {
	int n = 1;
	int valide = 0;
	int absent = 0;
	int pnote = 20;
	int gnote = 0;
	float note = 0;
	float nbre = 0;
	float somme = 0;
	float moyenne = 0;
	char question = 'A';
	int continuer = 0;



	while ((n<=30) & (continuer==0)) {
		printf("Entrez votre note no%d :\n", n);
		scanf_s("%f", &note);

		if ((note <= 20) && (note >= 0)) {
			somme += note;
			nbre += 1;
			n += 1;
			valide += 1;
			if (note > gnote) {
				gnote = note;
			}
			if (note < pnote) {
				pnote = note;
			}
		}
		else {
			printf("Elève absent ? ou voulez-vous arrêter la saisie des notes ? A / O / N\n");
			question = _getch();  // ça c'est comme un scanf mais pour des caractères (3 dernières biblio pour ça)
			question = toupper(question);

				switch (question){
				case 'A' : 
					printf("Un éléve est absent !\n");
					absent += 1;
					break;
				case 'O' : 
					printf("Ok on s'arrête\n");
					continuer = 1;
					break;
				case 'N' :
					printf("Ok on continue\n");
					break;

				}
		}
	}
	moyenne = somme / nbre;
	printf("La moyenne est de %f\n", moyenne);
	printf("Il y a %d absence\n", absent);
	printf("La plus grande note est %d\n", gnote);
	printf("La plus petite note est %d\n", pnote);

}