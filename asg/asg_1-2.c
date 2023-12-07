#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int x = 0, y = 0;
    printf("Enter any number:\n");
    scanf("%d",&x);
    printf("Enter the nth bit to toggle (0-31):");
    scanf("%d",&y);
    x^= 1<<y;
    printf("Toggled number: %d\n",x);
return (0);
}
