#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int x;

	do 
	{
		printf("enter a number less than 10\n");
		scanf("%d", &x);
	}while (x < 10);
return (0);
}
