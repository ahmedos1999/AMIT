#include "asg_6-1.h"

int main ()
{
	int i;
	std school[5];
	
	for (i = 0; i < 5; i++)
	{
		printf("\nEnter Student No.%d Data\n\n", i + 1);
		printf("Enter Student No.%d Name : ",i + 1);
		scanf(" %[^\n]s", &school[i].name);
		while ((getchar()) != '\n' && (getchar()) != EOF)
			continue;
		printf("Enter Student No.%d Age : ",i + 1);
		scanf("%d", &school[i].age);
		while ((getchar()) != '\n' && (getchar()) != EOF)
			continue;
		printf("Enter Student No.%d Degree : ",i + 1);
		scanf("%d", &school[i].degree);
		while ((getchar()) != '\n' && (getchar()) != EOF)
			continue;
		printf("Enter Student No.%d Section : ",i + 1);
		scanf("%d", &school[i].section);
		while ((getchar()) != '\n' && (getchar()) != EOF)
			continue;
	}
	print_struct(school);

	return (0);
}
