#include <stdio.h>
void main()
{
int meterno,pr,nr,nu,rate,bill;
printf ("\n enter meterno,pr,nr,nu");
scanf ("\n %d %d %d %d",&meterno,&pr,&nr,&nu);
printf ("\n given meterno=%d,pr value=%d,nr value=%d,nu value=%d",meterno,pr,nr,nu);
if (nu<100)
{
rate=3;
printf ("\n bill amount=%d",3*nu);
}
else if (nu>=100<200)
{
rate=5;
printf ("\n bill amount=%d",5*nu);
}
else if (nu>=200<300)
{
rate=6;
printf ("\n bill amount=%d",6*nu);
}
else if (nu>=300<500)
{
rate=8;
printf ("\n bill amount=%d",8*nu);
}
else 
{
rate=10;
printf ("\n bill amount=%d",10*nu);
}
getch();
}
