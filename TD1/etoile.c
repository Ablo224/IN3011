#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int n;
	n=9;
	for(int j=0;j<=9;j++)
	{
		
		for(int i=0;i<=n;i++)
		{
			printf(" ");
		}
		printf("*");
		printf("\n");
		n--;
	}
	
	return 0;
}
