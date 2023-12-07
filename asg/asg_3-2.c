#include <stdio.h>
#include <stdlib.h>

int z = 0;
/**
 * Recursive Function
 **/
int fibonacci_r (int x, int y, int n)
{
	if (x == 0)
	{
		n -= 2;
		printf("Recursive Fibonacci Series : %d, %d, ", x, y);
	}
	if (n > 0)
	{	
		z = x + y;
		printf("%d, ",z);
		return (fibonacci_r(y, z,--n));
	}
	else
		printf("\n");
}


/**
 * Iterative Function
 **/
int fibonacci_i (int x, int y , int n)
{
	int nextTerm = x + y, i = 0;

	printf("Iterative Fibonacci Series: %d, %d, ", x, y);

	for (i = 3; i <= n; ++i) 
	{
		printf("%d, ", nextTerm);
		x = y; 
		y = nextTerm;
		nextTerm = x + y;
	}
	printf("\n");
return (0);
}

int main ()
{
	int num = 0;

	printf("Enter the number of terms to be printed:\n");
	scanf("%d",&num);
	fibonacci_r(0, 1, num);
	fibonacci_i(0, 1, num);
	return (0);
}
