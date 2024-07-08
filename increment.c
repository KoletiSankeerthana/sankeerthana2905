#include <stdio.h>
int main()
{
	int x = 5;
	int y = 8;
	int a = 0;
	int b = 0;
	printf("\n x=%d,a=%d", x, a);
	/*first the value is assigned to a then x gets incremented*/
	a = x++;
	printf("\n postfix of x=%d,a=%d", x, a);
	printf("\n y=%d,b=%d", y, b);
	/*first y gets incremented then y is assigned to b*/
	b = ++y;
	printf("\n prefix of y=%d,b=%d", y, b);
	return 0;
}