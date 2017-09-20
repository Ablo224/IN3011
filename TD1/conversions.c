#include <stdio.h>
#include <stdlib.h>

void convertions(int t)
{
	int s,min,hr;
	s = t % 60;
	t = t / 60;
	min = t % 60;
	hr = t / 60;
	if(hr > 0)
	{
		printf("\n");
		printf("ce temps vaut : %d heure(s) %d minute(s) %d seconde(s)",hr,min,s);
		printf("\n");
	}
	else
	{
		printf("\n");
		printf("ce temps vaut : %d minute(s) %d seconde(s)",min,s);
		printf("\n");
	}
	
}


int main()
{
	int t;
	
	printf("Donner le temps à convertir : ");
	scanf("%d",&t);
	convertions(t);
	
return 0;
}
