#include <stdio.h>
#define swap(x,y){printf("\n swap (%d,%d)macro",x,y);\
int temp=y;\
y=x;\
x=temp;}

int main()
{
	int a=12,b=34;
	printf ("\n before swap a=%d,b=%d",a,b);
	swap(a,b);
	printf("\n after swap a=%d,b=%d",a,b);
	return 0;
}

