#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int somme_diviseurs(int n)
{
	int som_div;
	som_div = 0;
	for(int i=1;i<=n/2;i++)
	{
		if(n%i == 0)
			som_div +=i;
	}
	
	return som_div;
}

void couple_amis(int NMAX)
{
	int n,m;
	n=2;
	while((m=n+1)<=NMAX)
	{
		for(;m<=NMAX;m++)
		{
			if((somme_diviseurs(n) == m)  && (somme_diviseurs(m) == n))
				printf("(%d , %d)\n",n,m);
		}
		n++;
	}
}

int main()
{
	int nbr1,nbr2;
	int NMAX;
	NMAX = 5000;
	nbr1 = 220;
	nbr2 = 284;
	if((somme_diviseurs(nbr1) == nbr2) && (somme_diviseurs(nbr2) == nbr1))
	{
		printf("%d et %d sont amis\n",nbr1,nbr2);
	}
	else
	{
		printf("%d et %d ne sont  pas amis\n",nbr1,nbr2);
	}
	couple_amis(NMAX);
	
	return 0;
}
