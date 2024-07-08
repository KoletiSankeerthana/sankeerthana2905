#include <stdio.h>
int main()
{
	int num[5]={0};
	int value=99;
	int square[5];
	int i;
	
	for ( i=0;i<5;i++)
	{
	  value+=2;
		if(value%2!=0)
		{
		
		num[i]=value;
	}
		printf ("\n %d is odd",num[i]);
    }
	
    for (i=0;i<5;i++)
    {
    	square[i]=num[i]*num[i];
    printf ("\n %d*%d=%d",num[i],num[i],square[i]);
	}
	return 0;
	
	
}
