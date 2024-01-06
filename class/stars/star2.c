#include <stdio.h>

int main(void)
{
	int rows = 0, space;
	int i, j;

	printf("How Many Star Rows dow You Want ?\n");
	scanf("%d", &rows);

	for (i = 1; i <= rows; i ++)
	{
		for (space = rows - i; space > 0 ; space--)
			putchar(' ');
		for (j = i; j > 0; j --)
			putchar('*');
		for (j = i - 1; j > 0; j --)
			putchar('*');
		putchar('\n');
	}
return (0);
}
