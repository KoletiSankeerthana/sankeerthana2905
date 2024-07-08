#include<stdio.h>
int main()
{
int units;
float amt,totalamt,surcharge;
printf ("\n enter total no.of units consumed");
scanf ("%d",&units);
if (units<=50)
{
	amt=units*0.50;
}
else if (units<=150)
{
   amt=25+((units-50)*0.75);
} 
else if (units<=250)
{
     amt=100+((units-150)*1.20);
}
else 
{
	amt=250+((units-250)*1.50);
}
surcharge=amt*0.20;
totalamt=amt+surcharge;
printf ("\n electricity bill=Rs%f",totalamt);
return 0;
}
