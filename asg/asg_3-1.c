#include <stdio.h>
#include <stdlib.h>

/**
 * Could Have used the XOR(^) operator aswell
 **/

void swap (int *x, int *y)
{
	printf("Numbers Bfore Swapping\n");
	printf("x = %d\ty = %d\n", *x, *y);
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
	printf("Numbers After Swapping\n");
	printf("x = %d\ty = %d\n", *x, *y);
}

int main ()
{
	int num1 = 0, num2 = 0;

	printf("Enter Two numbers to swap:\n");
	scanf("%d%d", &num1, &num2);
	swap(&num1,&num2);
	return (0);
}
