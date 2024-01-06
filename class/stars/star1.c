#include <stdio.h>

int main(void)
{
	int rows = 0;
	int i, j = 0, star, space;

	printf("How Many Star Rows dow You Want ?\n");
	scanf("%d", &rows);

	for (i = 1; i <= rows; i ++)
	{
		for (space = rows - i; space > 0 ; space--)
			putchar(' ');
		for (star = i + j; star > 0; star--)
			putchar('*');
		j++;
		putchar('\n');
	}
return (0);
}
