#include <stdio.h>
int main()
{
	int n,x,r,sum=0;
	printf ("\n enter any value");
	scanf ("%d",&n);
	x=n;
	while(n>0)
	{
		r=n%10;
		sum=(r*r*r)+sum;
		n/=10;
	}
	if (sum==n)
	{
		printf ("\n armstrong");
	}
	else
        {
        	printf ("\n not armstrong");
		}
		return 0;
}
