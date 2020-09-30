#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include<locale.h>
#define NBMAXNOTES 30
#include <math.h>
#define carre(x) (x)*(x)

int main() {
	int n = 1;
	int i = 0;
	int valide = 0;
	int absent = 0;
	float pnote = 20;
	float gnote = 0;
	float nbre = 0;
	float somme = 0;
	float moyenne = 0;
	char question = 'A';
	int continuer = 0;


	float note[NBMAXNOTES];

	for (i = 0; i <= 29; i++) {
		note[i] = -2;
	}



	while ((n <= 30) & (continuer == 0)) {
		printf("Entrez votre note no%d :\n", n);
		scanf_s("%f", &note[n - 1]);

		if ((note[n - 1] <= 20) && (note[n - 1] >= 0)) {
			somme += note[n - 1];
			nbre += 1;
			valide += 1;

			if (note[n - 1] > gnote) {
				gnote = note[n - 1];
			}
			if (note[n - 1] < pnote) {
				pnote = note[n - 1];
			}
			n += 1;
		}
		else {
			printf("Elève absent ? ou voulez-vous arrêter la saisie des notes ? A / O / N\n");
			question = _getch();  // ça c'est comme un scanf mais pour des caractères (3 dernières biblio pour ça)
			question = toupper(question);

			switch (question) {
			case 'A':
				printf("Un éléve est absent !\n");
				absent += 1;
				note[n - 1] = -1;
				n++;
				break;
			case 'O':
				printf("Ok on s'arrête\n");
				continuer = 1;
				break;
			case 'N':
				printf("Ok on continue\n");
				break;

			}
		}
	}
	moyenne = somme / nbre;
	printf("La moyenne est de %f\n", moyenne);
	printf("Il y a %d absence\n", absent);
	printf("La plus grande note est %f\n", gnote);
	printf("La plus petite note est %f\n", pnote);
	int d = 0;
	float tout = 0;
	float ecarttype = 0;

	for (d = 0; d <= 29; d++) {
		if ((note[d] == -1) | (note[d] == -2)) {
		tout += (carre(note[d] - moyenne));
		}
	}
	ecarttype = (float)sqrt((1 / ((n - absent) - 1))*tout);
	printf("L'écart type est de %f\n", ecarttype);
}