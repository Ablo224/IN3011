#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficher_taille_mem(void)
{
	printf("taille d'un CHAR: %lu\n",sizeof(char));
	printf("taille d'un INT: %lu\n",sizeof(int));
	printf("taille d'un DOUBLE: %lu\n",sizeof(double));
	printf("taille d'un CHAR*: %lu\n",sizeof(char*));
	printf("taille d'un VOID*: %lu\n",sizeof(void*));
	printf("taille d'un DOUBLE*: %lu\n",sizeof(double*));
	printf("taille d'un INT*: %lu\n",sizeof(int*));
	printf("taille d'un INT**: %lu\n",sizeof(int**));
	printf("taille d'un INT[10]: %lu\n",sizeof(int[10]));
	printf("taille d'un CHAR[7][3]: %lu\n",sizeof(char[7][3]));
	//printf("taille d'un INT[]: %lu\n",sizeof(int[]));
	char tab[10];
	printf("\n\n");
	printf("taille de TAB: %lu\n",sizeof(tab));
	printf("taille de TAB[0]: %lu\n",sizeof(tab[0]));
	printf("taille de &TAB[0]: %lu\n",sizeof(&tab[0]));
	printf("taille de *&TAB: %lu\n",sizeof(*&tab));
	printf("taille de *&TAB[0]: %lu\n",sizeof(*&tab[0]));
	printf("\n\n");
	char (*p)[10]=&tab;
	printf("taille de P: %lu\n",sizeof(p));
	printf("taille de *P: %lu\n",sizeof(*p));
	printf("taille de (*P)[2]: %lu\n",sizeof((*p)[2]));
	printf("taille de &(*P)[2]: %lu\n",sizeof(&(*p)[2]));

	
}

void Permutation(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

void reinitPointeur(int* (*p))
{
	*p=NULL;
	//printf("%p\n",*p);
}

int main()
{	
	//afficher_taille_mem();
	/*int a=15;
	int b=6;
	int* c;
	Permutation(&a,&b);
	printf("a = %d et b = %d\n",a,b);
	reinitPointeur(&c);*/
	
	int a=1;
	int *p=&a;
	reinitPointeur(&p);
	printf("ha ça marche!!!  '%p\n",p);
	

	return 0;
}
