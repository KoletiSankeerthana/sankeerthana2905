#include <stdio.h>
int main()
{
	int i,x=0,sum=0;
	
	for (i=0;i<=5;i++)
	{
		printf ("\n enter positive value:");
		scanf("%d",&x);
	
	if(x<=0)
	{
		printf(" You entered negative value");
		continue;
	}
	sum+=x;
}
printf("\n sum=%d",sum);
return 0;
}
