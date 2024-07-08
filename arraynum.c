#include <stdio.h>
int maxnum(int[],int);
int function1 (int[],int);
int main()
{
	int numelem=3;
	int digit[3]={4,7,9};
	int maxval;
	int i;
	for (i=0;i<3;i++)
	{

		printf("\n %d",digit[i]);
}
	maxval=maxnum(digit,numelem);
	printf("\n maxval=%d",maxval);
	
	function1(digit,numelem);
	
	for (i=0;i<3;i++)
	{
	
	printf("\n %d",digit[i]);
}
	return 0;
}
maxnum(int arr[],int n)
{
	int maxval=0;
	maxval=(arr[0]>arr[1])?arr[0]:arr[1];
	maxval=(maxval>arr[2])?maxval:arr[2];
	return maxval;
}
int function1(int arr[],int n)
{
	int i;
	for (i=0;i<3;i++)
	{
		arr[i]=2*arr[i];
	}
	return 0;
}

