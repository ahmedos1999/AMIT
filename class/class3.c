#include <stdio.h>
#include <stdlib.h>

int main()
{
	int no1 = 0, no2 = 0, no3 = 0;

	printf("Eneter Three numbers\n");
	scanf("%d%d%d",&no1 ,&no2 ,&no3);
	if (no1 >= no2)
	{
		if (no1 >= no3)
			printf("No.1 is the Max\n");
		else
			printf("No.3 is the Max\n");
	}
	else
	{
		if (no2 >= no3)
			printf("No.2 is the Max\n");
		else
			printf("No.3 is the Max\n");
	}
	return 0;
}
