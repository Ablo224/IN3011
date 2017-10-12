#include <stdio.h>


extern char *p1;
extern char tab1[];
extern char p2[];  /* déclaration de tableau alors que p2 est défini en pointeur */
extern char *tab2; /* déclaration de pointeur alors que tab2 est défini en tableau */

int main(void) {


	puts(p1);
	puts(tab1);
	puts(p2);
	puts(tab2);
	return 0;

}
