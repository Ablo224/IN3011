#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fact(int n)
{
	if(n == 0 || n == 1)
		return 1;
	return  n*fact(n-1);;
}

int main()
{
	int n;
	srand(time(NULL));
	n =rand() % 10;
	printf(" %d factorielle est : %d \n",n,fact(n));
	
	return 0;
}
