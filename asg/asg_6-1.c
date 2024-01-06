#include "asg_6-1.h"

int main ()
{
	int i;
	std school[5];
	
	for (i = 0; i < 5; i++)
	{
		printf("Enter Student No.%d Data\n\n", i + 1);
		printf("Enter Student No.%d Name : ",i + 1);
		scanf(" %[^\n]s", &school[i].name);
		printf("Enter Student No.%d Age : ",i + 1);
		scanf("%d", &school[i].age);
		printf("Enter Student No.%d Degree : ",i + 1);
		scanf("%d", &school[i].degree);
		printf("Enter Student No.%d Section : ",i + 1);
		scanf("%d", &school[i].section);
	}
	print_struct(school);

	return (0);
}
