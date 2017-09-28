#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float calculS(float epsilon)
{
	float S,Sprec;
	int n;
	n=1; Sprec = 0.0;
	do
	{
		S = Sprec + 1./(n*n);
		n=n+1;
	}while(S -Sprec > epsilon);
return S;
}

/*int main()
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
}*/

int main()
{
	float epsilon;
	float S=0.0;
	epsilon = 1e-3;
	S = calculS(epsilon);
	
	printf("%f\n",S);
	
	return 0;
}
