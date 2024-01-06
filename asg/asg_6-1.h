#ifndef ASG_6_1_H
#define ASG_6_1_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	char name[20];
	int age;
	int degree;
	int section;	
}std;
void print_struct (std[5]);


void print_struct (std person[5])
{
	int i;

	for(i = 0; i < 5; i++)
	{
		printf("Student No.%d Data:\n", i + 1);
		printf("Name: %s\nAge: %d\nDegree: %d\nSection: %d\n\n", person[i].name, person[i].age, person[i].degree, person[i].section);
	}
}


#endif	/* ASG_6_1_H */
