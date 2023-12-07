#include <stdio.h>
#include <stdlib.h>

void edit (int *x)
{
	*x ^= 1 << 4;
}

int main ()
{
	int x = 0;

	printf("Enter the value of X:\n");
	scanf("%x", &x);
	printf("Value of X Before Edit : %x\n", x);
	edit(&x);
	printf("Value of X After Edit : %x\n", x);
	return (0);
}
