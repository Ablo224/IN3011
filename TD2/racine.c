#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double  fonction_racine(double n)
{
	double racine = 0.0;
	double d,f,err;
	d = 0.0;
	f=n;
	racine = (d+f)/2;
	err = 0.05;
	while((racine*racine>n+err) || (racine*racine<n-err))
	{
		if((d*d>n+err)&&(d*d<n-err))
		{
			racine = d;
			return racine;
		}
		if((f*f>n+err)&&(f*f<n-err))
		{
			racine = f;
			return racine;
		}
		if(racine*racine>n+err)
		{
			f=racine;
		}
		if(racine*racine<n-err)
		{
			d = racine;
		}
		racine = (d+f)/2.0;
	}
		
return  racine;
}

int main()
{
	double n;
	srand(time(NULL));
	n=rand() %10000;
	printf("la racine de %lf est %lf\n",n,fonction_racine(n));
	
	return 0;
}
