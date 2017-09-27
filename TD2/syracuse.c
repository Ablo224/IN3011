#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int Uo,i,U;
	printf("donner la valeur de Uo: ");
	scanf("%d",&Uo);
	while(Uo>1)
	{
		if(Uo%2 == 0)
		{
			U=Uo/2;
		}
		else
		{
			U=3*Uo +1;
		}
		Uo=U;
		i++;
		printf("%d ,  ",U);
	}
	printf("\n%d nombre d'incrémentation\n",i);
	
	return 0;
}
