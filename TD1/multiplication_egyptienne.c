#include <stdio.h>
#include <stdlib.h>

void multiplication(int x,int y)
{
	int X,Y,rest;
	X=x;
	Y=y;
	rest=0;
	
	printf("               %d * %d\n",x,y);
	while(X > 1)
	{
	if(x%2 == 0)
	{
		 X = x/2;
		 Y = 2*y;
		 printf("          = %d * %d + %d",X,Y,rest);
		 x = x/2;
		 y = Y;
		 
	}
	else if(x % 2 !=0)
	{
		X = x-1;
		rest += y;
		printf("          = %d * %d + %d",X,y,rest);
		x = x-1;
		
		
	}
	printf("\n");
	}
	printf("          = %d\n",y+rest);


		
}



int main()
{
	
	multiplication(23,87);
	
	
	return 0;
	
}
