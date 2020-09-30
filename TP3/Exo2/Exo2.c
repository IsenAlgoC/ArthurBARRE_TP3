#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	int c = 2868838400;
	int i = 1;
	printf(" Le nombre d'octet pour 2868838400 est de %d\n", sizeof(c));
	printf("Le nombre de bits pour 2868838400 est de %d\n" ,(sizeof(c)*8));
	
	// Ici on compare nos bits, le c&1 prend le lsb, on le compare ensuite à 1 
	// l'opérateur >> nous sert à décaler notre chiffre binaire pour avancer dans la comparaison

	for (i = 1; i <= 32; i++) {
		if ((c & 1) == 1) {
			printf("bits %d = ON\n", i);
			c = c >> 1;
		}
		else {
			printf("bits %d = OFF\n", i);
			c = c >> 1;
		}
	}
	printf("Au plaisir de vous revoir");
}