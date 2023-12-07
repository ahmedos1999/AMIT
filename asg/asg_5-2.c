#include <stdio.h>
#include <stdlib.h>

void swap (int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void display (int array[], int size)
{
	int i =0;
	
	printf("The Elements of The Array : ");
	for(i = 0; i < size; i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n"); 
}

int main ()
{
	unsigned int size = 0;
	int i = 0, j = 0;

	printf ("Enter the size of the Array: \n");
	scanf("%d",&size);

	int arr[size];
	j = size - 1;

	printf("Enter the Elements of the array : \n");

	for (i = 0; i < size; i++)
	{
		scanf("%d", arr + i);
	}
	i = 0;
	display(arr, size);
	while (i < j)
	{
		swap(arr + i, arr + j);
		i++;
		j--;
	}
	display(arr, size);
	return (0);
}
