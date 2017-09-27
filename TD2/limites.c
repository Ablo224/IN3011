#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
	double precision=0.01;
	double lim = 0;
	int i = 1;
	
	printf("Donner la précision superieur à 0.01:");
	scanf("%lf",&precision);
	
	while((1.0/pow(i+1.0,2.0))>precision)
	{
		lim = lim + (1.0/pow(i,2.0));
		i++;
	}
	
	printf("la limite est égale : %lf`\n",lim);

return 0;
}
