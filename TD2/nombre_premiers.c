#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int nbr;
	srand(time(NULL));
	nbr = rand () % 100;
	for(int i=2;i*i<=nbr;i++)
	{
		if(nbr%i == 0)
		{
			printf("le nombre %d  n'est pas premier\n",nbr);
			return 0;
		}
	}
	
	printf("le nombre %d est premier\n",nbr);
	
	return 0;
}
