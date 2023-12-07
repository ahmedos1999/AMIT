#include<stdio.h>
#include<stdlib.h>

int main(){
	int x = 0, y = 0, z = 0;
	
	printf("Please enter three numbers\n");
	scanf("%d%d%d",&x ,&y ,&z);
	x == y && x == z ? (printf("first = second = third = %d\n", x)) :
	(x >= y && x >= z ? ( x == y ? (printf("first equal second\n") ) :
		(x == z ? (printf("first equal third\n")) : 
			(printf("first is max\n")) ) ) : 
		( y >= z ? (y == z ? (printf("second equal third\n")) : (printf("second is max\n"))) :
			(printf("third is max\n")) ) 
	);
	return 0;
}
