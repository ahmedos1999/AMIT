#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	char x;

	printf("Enter a small letter\n");
	while (true)
	{
		scanf("%c",&x);
		if (x >= 'a' && x <= 'z')
		{
			if (x == 'a')
				printf("capital letter: %c\n", x - 32);
			else if (x == 'b')
				printf("capital letter: %c\n", x - 32);
			else if (x == 'c')
				printf("capital letterr: %c\n", x - 32);
			else
				printf("Try Another small letter\n");
		}	
		else
		{
			printf("Try Again\n");
		}
	}
return (0);
}
