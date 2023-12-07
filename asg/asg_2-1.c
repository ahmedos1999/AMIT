#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char op;
    int num1 = 0, num2 = 0;

/**
 * Used the %*c specifier to discard the '\n' character 
 * and take the next character as the Operator
 **/
    printf("Enter first number\n");
    scanf("%d",&num1);
    printf("Enter Operator (+ , - , * , /)\n");
    scanf("%*c%c",&op);
    printf("Enter second number\n");
    scanf("%d",&num2);

    switch (op)
        {
        case '+':
            {
            printf("Result = %d\n",num1+num2);
            break;
            }
        case '-':
            {
            printf("Result = %d\n",num1-num2);
            break;
            }
        case '*':
            {
            printf("Result = %d\n",num1*num2);
            break;
            }
        case '/':
            {
            printf("Result = %d\n",num1/num2);
            break;
            }
        }
    return 0;
}
