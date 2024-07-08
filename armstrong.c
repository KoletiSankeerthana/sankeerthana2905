#include<stdio.h>
int main()
{
	int n,x,r,sum=0;
	printf ("\n enter any value");
	scanf ("%d",&n);
	x=n;
	while(x>0)
	{
		r=x%10;
		sum+=(r*r*r);
		x=x/10;
	}
	if (sum==n)
	{
		printf ("\n %d is armstrong number",n);
	}
	else 
	{
		printf ("\n %d is not armstrong number",n);
	}
return 0;
}
