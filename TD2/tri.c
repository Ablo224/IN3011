#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 1000

int alea(int n)
{
	return rand()%n;
}

void Remplissage(int tab[NMAX],int n)
{
	for(int i=0;i<n;i++)
	{
		tab[i] = alea(100);
	}
}

//fonction qui compte le nombre de valeurs differentes
int NombreValeursDifferentes(int tab[NMAX],int n)
{
	int nbre_val = n;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(tab[i] == tab[j])
			{
				nbre_val--;
			}
		}
	}
	return nbre_val;
}

//fonction d'affichage
void afficher(int Tab[NMAX],int taille_tab)
{
	for(int i=0;i<taille_tab;i++)
	{
		printf("%d  ",Tab[i]);
	}
	printf("\n");
}

int main()
{
	
	int tab[NMAX],n;
	n=10;
	srand(time(NULL));
	Remplissage(tab,n);
	afficher(tab,n);
	printf("le nombre de valeurs différentes est : %d\n",NombreValeursDifferentes(tab,n));
	
	return 0;
}
