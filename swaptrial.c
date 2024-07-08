#include <stdio.h>
int main()
{
	int a,b;
	printf("\n enter values for a,b=");
	scanf("%d %d",&a,&b);
	a=a*b;
	b=a/b;
	a=a/b;
	printf("\n after swaping a=%d,b=%d",a,b);
	return 0;
	
}
