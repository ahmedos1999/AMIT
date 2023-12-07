#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
	int sum = 0, rem = 0, cpy = 0, num_of_digits = 0, arm = 0;

	printf("Enter a number to check\n");
	scanf("%d",&arm);

	cpy = arm;
	for (cpy = arm; cpy != 0; num_of_digits++)
	{
		cpy /= 10;
	}
	for (cpy = arm; cpy != 0; cpy /= 10)
	{
		rem = cpy % 10;
		sum += pow(rem, num_of_digits);
	}
	if (sum == arm)
		printf("The number : %d is an Armstrong number\n",arm);
	else
		printf("The number : %d is NOT an Armstrong number\n",arm);

return (0);
}
