#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 1000

struct tableau{
	int taille;
	int tab[NMAX];
};
typedef struct tableau Tableau;

//fonction retournant un nombre aléatoire entre 0 et n
int alea(int n)
{
	return rand()%n;
}

//fonction qui initialise les éléments de la structure
void init_tableau(Tableau *a)
{
	for(int i=0;i<(*a).taille;i++)
	{
		(*a).tab[i]=alea(100);
	}
}


//fonction d'affichage
void Affichage(Tableau *t)
{

	for(int i=0;i<(*t).taille;i++)
	{
		printf("%d  ",(*t).tab[i]);
	}
	printf("\n");
}

//fonction qui retourne l'indice du minimum
int Imin(Tableau *t,int i)
{
	int iMin=i;
	int d=i;
	for(d=i+1;d<(*t).taille;d++)
	{
		if((*t).tab[iMin]>(*t).tab[d])
		{
			iMin=d;
		}
	}
	return iMin;
}

//procedure qui échange deux valeur
void Echange(Tableau *t,int i,int j)
{
	int tmp;
	tmp = (*t).tab[i];
	(*t).tab[i] = (*t).tab[j];
	(*t).tab[j] = tmp;
}

//Tri par sélection de manière récursif
void TriSelectRecursif(Tableau *t,int d)
{
	if(d>=(*t).taille)
	{
		return;
	}
	Echange(t,d,Imin(t,d));
	return TriSelectRecursif(t,d+1);
}

//Tri par sélection
void TriSelect(Tableau *t)
{
	int temp,iMin=0;
	for(int i=0;i<(*t).taille;i++)
	{
		if((*t).tab[iMin] != (*t).tab[i])
		{
			iMin = Imin(t,i);
			temp=(*t).tab[iMin];
			(*t).tab[iMin] = (*t).tab[i];
			(*t).tab[i] = temp;
		}
	}
		
}		

//Tri d'insertion
void TriInsertion(Tableau *t)
{
	int i,j,temp;
	for(i=1;i<t->taille;i++)
	{
		temp = t->tab[i];
		j=i;
		while(j>0 && t->tab[j-1]>temp)
		{
			t->tab[j] = t->tab[j-1];
			j--;
		}
		t->tab[j]=temp;
	}

}

//Tri à Bulle
void TriABulle(Tableau *t)
{
	int temp=0;
	for(int Tc=1;Tc<(*t).taille && temp == 0;Tc++)
	{
		temp=1;
		for(int i=(*t).taille-1;i>=Tc;i--)
		{
			
			if((*t).tab[i-1]>(*t).tab[i])
			{
				Echange(t,i,i-1);
				temp=0;
			}
		}
		Affichage(t);
	}
}

//Fonction de Partition
int Partition(Tableau *t,int g,int d)
{
	int i,j,pivot;
	pivot = (*t).tab[g];
	i=g+1; j=d;
	while(i<=j)
	{
		while((*t).tab[i]<=pivot){i++;}
		while((*t).tab[j]>pivot){j--;}
		if(i<j)
		{
			Echange(t,i,j);
			i++;
			j--;
		}
	}
	Echange(t,g,j);
	Affichage(t);
	return j;
}

//Tri Rapide
void TriRapide(Tableau *t,int d,int f)
{
	int p=0;
	if(d<f)
	{
		p = Partition(t,d,f);
		TriRapide(t,d,p-1);
		TriRapide(t,p+1,f);
	}
}
		
	



int main()
{
	srand(time(NULL));
	Tableau t;
	int n=15; t.taille = n;int i=0;
	int m=n-1;
	init_tableau(&t);
	printf("AVANT TRI: \n");
	Affichage(&t);
	//printf("Tri Par Insertion: \n");
	//TriInsertion(&t);
	//Affichage(&t);
	//printf("\nTri a Bulle: \n");
	//TriABulle(&t);
	//Affichage(&t);
	//printf("\nTri par Sélection: \n");
	//TriSelect(&t);
	//Affichage(&t);
	//printf("%d",Imin(&t,0));*/
	//TriSelectRecursif(&t,i);
	//Affichage(&t);
	//printf(" %d \n",Partition(&t,0,14));
	//Partition(&t,i,m);
	TriRapide(&t,i,m);
	Affichage(&t);
	
	
	
	
	
	return 0;
}
