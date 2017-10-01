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
	}while(S - Sprec > epsilon);
return S;
}



int main()
{
	float epsilon;
	float S=0.0;
	epsilon = 1e-3;
	S = calculS(epsilon);
	
	printf("%f\n",S);
	
	return 0;
}
