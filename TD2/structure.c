#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 1000

//définition de la structure
struct Tableau{
	int taille;
	int tab[100];
};

typedef struct Tableau Tableau;

//fonction alea
int alea(int n)
{
	return rand()%(n+1);
}

//procedure qui échange deux valeur
void Echange(Tableau *t,int i,int j)
{
	int tmp;
	tmp = (*t).tab[i];
	(*t).tab[i] = (*t).tab[j];
	(*t).tab[j] = tmp;
}


//initialisation de la structure Tableau
void init_struct_tab(Tableau *t,int n)
{
	(*t).taille=n;
	for(int i=0;i<(*t).taille;i++)
	{
		(*t).tab[i] = alea(20);
	}
}

//fonction d'affichage
void affichage(Tableau *t)
{
	for(int i=0;i<(*t).taille;i++)
	{
		printf(" %d ",(*t).tab[i]);
	}
	printf("\n");
}

//Produit des element du tableau recursive
long int produit_elem_tab_rec(Tableau *t,int i)
{
	long int prod=1;
	if(i>=(*t).taille){return prod;}
	else
		prod *= (*t).tab[i];
	return prod = prod * produit_elem_tab_rec(t,i+1);
}

//Produit des element du tableau itérative
long int produit_elem_tab(Tableau *t)
{
	long int prod = 1;
	for(int i=0;i<(*t).taille;i++)
	{
		prod *= (*t).tab[i];
	}
	return prod;
}

//valeur minimal du tableau
int min(Tableau *t)
{
	int min=(*t).tab[0];
	for(int i=1;i<(*t).taille;i++)
	{
		if((*t).tab[i]<min)
		{
			min = (*t).tab[i];
		}
	}
	return min;
}

//decalage à droite de tous les éléments d'un tableau
void decalage(Tableau *t)
{
	(*t).taille = (*t).taille + 1;
	for(int i=(*t).taille-1;i>1;i--)
	{
		(*t).tab[i]=(*t).tab[i-1];
	}
	(*t).tab[0] = 0;
}

//decalage jusqu'à un indice donnée
void decalage_indice(Tableau *t,int j)
{
	for(int i=(*t).taille-1;i>j;i--)
	{
		(*t).tab[i]=(*t).tab[i-1];
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
		while((*t).tab[i]<=pivot && i<=j){i++;}
		while((*t).tab[j]>pivot && i<=j){j--;}
		if(i<j)
		{
			Echange(t,i,j);
			i++;
			j--;
		}
	}
	Echange(t,g,j);
	//affichage(t);
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

//indice insertion
int indice_insertion(Tableau *t,int elem)
{ 
	int indice=0;
	while(elem > (*t).tab[indice] && indice < (*t).taille)
	{
		indice++;
	}
	return indice;
}

//Insertion d'un élément dans un tableau trié
void inserer_elem_tri(Tableau *t,int elem)
{
	(*t).taille=(*t).taille + 1;
	decalage_indice(t,indice_insertion(t,elem));
	if(indice_insertion(t,elem)<(*t).taille)
	{
		(*t).tab[indice_insertion(t,elem)] = elem;
	}
	else
	{
		(*t).tab[(*t).taille-1] = elem;
	}
}

//Inverse des valeurs du tableau
void inverse(Tableau *t)
{
	int i=0;
	int j=(*t).taille-1;
	while(i<j)
	{
		Echange(t,i,j);
		i++;j--;
	}
}	

//Rechercher un element dans un tableau
int indice_elem_rechercher(Tableau *t,int elem)
{
	int indice_elem = -1;
	for(int i=0;i<(*t).taille;i++)
	{
		if((*t).tab[i] == elem)
		{
			indice_elem = i;
			return indice_elem;
		}
	}
	printf("%d ne figure pas dans le tableau\n",elem); 
	
	return indice_elem;
}

//Suppresion de l'element trouver
void supp_elem(Tableau *t,int elem)
{
	int j=indice_elem_rechercher(t,elem);
	if(j != -1)
	{
		Echange(t,j,(*t).taille-1);
		(*t).taille = (*t).taille - 1;
	}
}

//elimation de doublons dans un tableau 
void supp_doublon(Tableau *t)
{
	for(int i=0;i<(*t).taille;i++)
	{
		for(int j=i+1;j<t->taille;j++)
		{
			if((*t).tab[i] == (*t).tab[j] && (*t).tab[j] != -1)
			{
				(*t).tab[j] = -1;
			}
		}
	}
			
}



int main()
{
	srand(time(NULL));
	Tableau t;
	//printf("la taille de la structure Tableau est : %lu\n",sizeof(Tableau));
	int n=10; //int i=0;
	t.taille = n;
	int m=n-1; //int elem;
	//long int prod=1;
	//long int prod1 =1;
	init_struct_tab(&t,n);
	affichage(&t);
	//prod = produit_elem_tab_rec(&t,i,n);
	//prod1 = produit_elem_tab(&t,n);
	//printf("%ld\n",prod);
	//printf("%ld\n",prod1);
	//printf("%d est la valeur minimale du tableau \n",min(&t));
	//decalage(&t);
	TriRapide(&t,0,m);
	affichage(&t);
	//printf("donner la valeur à inserer : ");
	//scanf("%d",&elem);
	//inserer_elem_tri(&t,elem);
	//inverse(&t);
	//printf("Donner l'element à supprimer : ");
	//scanf("%d",&elem);
	//supp_elem(&t,elem);
	supp_doublon(&t);
	affichage(&t);
	return 0;
}
