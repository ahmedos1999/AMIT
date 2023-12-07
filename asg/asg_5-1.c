#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap (int* a, int* b)
{
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main ()
{
	int arr_1[5];
	int i = 0, len = 5;
	int sorted = 0, done = 0, min = INT_MAX, max = 0;
	int pos_min = 0, pos_max = 0;

	printf("Enter 5 numbers :\n");
	for (i = 0; i < 5; i++)
	{
		scanf("%d",&arr_1[i]);
	}
	while (sorted == 0)
	{
		sorted = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (arr_1[i] > arr_1[i + 1])
			{
				swap(arr_1 + i, arr_1 + i + 1);	
				sorted = 0;
			}
		}
		len --;
	}
	
	while (done == 0)
	{
		done = 1;
		for (i = 0; i < 5; i++)
		{
			if (arr_1[i] > max)
			{
				max = arr_1[i];
				pos_max = i;
				done = 0;
			}
			if (arr_1[i] < 	min)
			{
				min = arr_1[i];
				pos_min = i;
				done = 0;
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d\t", arr_1[i]);
	}
	printf("\n");
	printf("Max number is %d at position arr_1[%d]\n",max, pos_max);
	printf("Min number is %d at position arr_1[%d]\n",min, pos_min);
	return (0);
}
