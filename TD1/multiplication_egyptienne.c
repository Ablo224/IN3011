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
		}
		else
		{
				x= x-1;
				rest += y;
		}
			printf("          = %d * %d + %d\n",x,y,rest);
			
		}
		printf("          = %d\n",y+rest);
}



int main()
{
	
	multiplication(23,87);
	
	
	return 0;
	
}
