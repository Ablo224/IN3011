#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 100


//fonction qui calcul le produit des element d'un tableau
int  produit_elem_tab(int Tab[NMAX],int n)
{
	int prod = 1;
	for(int i=0;i<n;i++)
	{
		prod= prod * Tab[i];
	}	
	return prod;
}

//fonction qui retourne le minimum dans un tableau
int minimum(int tab[NMAX],int n)
{
	int min = tab[0];
	for(int i=1;i<n;)
	{
		if(tab[i] < min)
		{
			min = tab[i];
		}
		i++;
	}
	return min;
}

//fonction de decalage à droit
void decalage(int tab[NMAX],int n)
{
	for(int i=n-1;i>0;i--)
	{
		tab[i] = tab[i-1];
	}
	tab[0] = 0;
}

//fonction qui insère un nombre dans un tableau trié
int InsertionElement(int tab[NMAX],int n,int elem)
{
	int i=0;
	while(elem > tab[i])
	{
		i++;
	}
	n = n+1;
	for(int k=n-1;k>i;k--)
	{
		tab[k] = tab[k-1];
	}
	tab[i] = elem; 
	return n;
}

//fonction inversant un tableau
void Inversion(int tab[NMAX],int n)
{
	int tmp,i,j;
	i=0; j=n-1;
	while(i!=j)
	{
		tmp = tab[j];
		tab[j] = tab[i];
		tab[i] = tmp;
		i++; j--;
	}
}

//elemination de doublon
void EliminerDoublons(int tab[NMAX],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		j=i+1;
		while(j<n)
		{
			if(tab[i] == tab[j])
			{
				if(tab[j] < 0)
				{
					break;
				}
				else
				{
					tab[j] = -tab[j];
				}
			}
			j++; 
		}
	}
}

//moyenne par section
float MoyenneParSection(int tab[NMAX],int n)
{
	float moy;
	float prod,som;
	int coef=0;
	som=0.0;prod=1.0;
	for(int i=0;i<n;)
	{
		if(tab[i] != 0)
		{
			prod *= tab[i];
			i++;
		}
		else if(tab[i] == 0)
		{
			som+=prod;
			while(tab[i] == 0)
			{
				i++;
				prod = 1;
			}
			coef++;
		}
	}
	if(prod != 0)
	{
		som+=prod;
		coef++;
	}
	moy = som/coef;
	return moy;
}

//fonction de saisie des val d'un tableau
void saisie_val(int tab[NMAX],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nvaleur n°%d : ",i);
		scanf("%d",&tab[i]);
	}
}

//fonction d'affichage
void affichage(int Tab[NMAX],int taille_tab)
{
	for(int i=0;i<taille_tab;i++)
	{
		printf("%d  ",Tab[i]);
	}
	printf("\n");
}


int main()
{
	int tab[NMAX];
	int n;
	printf("Donner la taille du tableau: ");
	scanf("%d",&n);	
	saisie_val(tab,n);
	affichage(tab,n);	
	//printf("le produit des éléments du tableau est: %d\n",produit_elem_tab(tab,n));
	//printf("%d est le minimu du tableau\n",minimum(tab,n));
	//decalage(tab,n);
	//printf("Après decalage voici les éléments du tableau:\n");
	//n = InsertionElement(tab,n,-1);
	//affichage(tab,n);
	//Inversion(tab,n);
	//printf("affichage après inversion du tableau: \n");
	//affichage(tab,n);
	EliminerDoublons(tab,n);
	printf("affichage après élimination des doublons: \n");
	affichage(tab,n);
	printf("\nla moyenne est :%f\n",MoyenneParSection(tab,n));

		
		
	
	return 0;
}
	
