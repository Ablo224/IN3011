#include <stdio.h>
#include <stdlib.h>

void multiplication(int x,int y)
{
	int rest;
	rest=0;
	
	printf("               %d * %d\n",x,y);
	while(x > 1)
	{
		if(x%2 == 0)
		{
		 x = x/2;
		 y = 2*y;
		 printf("          = %d * %d + %d",x,y,rest);
		}
		else if(x % 2 !=0)
		{
		x= x-1;
		rest += y;
		printf("          = %d * %d + %d",x,y,rest);
		}
		printf("\n");
		}
		printf("          = %d\n",y+rest);
}



int main()
{
	
	multiplication(42,87);
	
	
	return 0;
	
}
