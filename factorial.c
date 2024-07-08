#include <stdio.h>
int factorial(int);
int main ()
{

int n,result=0;
result=factorial(n);
printf ("\n enter any value for n");
scanf ("%d",&n);
printf ("\n %d! is %d",n,result);
return 0;
}
int factorial(int n)
{

if (n==1)
{
	printf ("\n %d",n);
	return 1;
}
printf ("%d x",n);
return (n*factorial(n-1));
}

