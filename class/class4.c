#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	
	printf("Enter a number between 1 and 3\n");
	scanf("%d",&num);
	switch (num) 
	{
		case 1:
			{
				printf("First case\n");
				break;
			}
		case 2:
			{
				printf("Second case\n");
				break;
			}
		case 3:
			{
				printf("Third Case\n");
				break;
			}
		default :
			{
				printf("Default case : Try again\n");
				break;
			}
	}
}
