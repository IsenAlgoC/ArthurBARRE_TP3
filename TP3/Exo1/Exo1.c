#include <stdio.h>
#include <stdlib.h>
#define carre(x) (x)*(x)

int main() {
	int Nb = 5;
	printf("%d", carre(Nb+1));    
	// Il suffit de rajouter des paranthèses, car sinon la macro fait Nb+1*nb+1 ce qui fait 11
}