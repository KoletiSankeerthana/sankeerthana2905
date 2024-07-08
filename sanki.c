#include <stdio.h>
void main()
{
int x,y;
printf ("\n enter values for x,y");
scanf (" %d %d",& x,& y);
printf ("\n the given x value=%d,y value=%d",x,y);
if(x>y)
{
printf (" \n x is greater than y");
}
else 
{
printf (" \n y is greater than x");
}
getch();
}
