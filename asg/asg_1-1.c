#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int x = 0;

    printf("Enter a number to check: Even or Odd\n");
    scanf("%d",&x);
    printf("value of x = %d\n", x);
    if ((x & 1))
    {
        printf("the number is odd = 1\n");
        printf("the number is even = 0\n");
    }
    else
    {
        printf("the number is odd = 0\n");
        printf("the number is even = 1\n");
    }
return (0);	
}
