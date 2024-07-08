#include <stdio.h>
#include <math.h>
int main()
{
	int a=0,b=1,n,i,result;
	printf ("\n enter any value for n:");
	scanf ("%d",&n);
	for (i=0;i<=n;i++)
	{
		printf ("%d",a);
		result=a+b;
		a=b;
		b=result;
	}
	return 0;
}
