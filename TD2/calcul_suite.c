#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double calcul(int NMAX,int n)
{
	if(n == NMAX)
	{
		return sqrt(n);
	}
	else
	{
	return sqrt(n+calcul(NMAX,(n+1)));
	}
}

int main()
{
	int r;
	int i;
	
	printf("Entré le rang de la suite: ");
	scanf("%d",&r);
	for(i=1;i<=r;i++)
	{
		printf("rang %d : %f\n",i,calcul(i,1));
	}
	
	
	return 0;
}
