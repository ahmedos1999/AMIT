#include <stdio.h>

typedef struct complexNumber {
	int real;
	int img;
} comp_num;


void addition(comp_num x, comp_num y, comp_num *result)
{

	result->real = x.real + y.real;
	result->img = x.img + y.img;
}

int main(void)
{
	comp_num a, b, sum;

	printf("Enter The Real and Imaginary values of the First number, Respectively : ");
	scanf("%d%d", &a.real,&a.img);
	printf("\nEnter The Real and Imaginary values of the Second number, Respectively : ");
	scanf("%d%d", &b.real,&b.img);
	addition(a, b, &sum);
	printf("\nComplex Summation = %d + %di\n", sum.real, sum.img);
return (0);
}
