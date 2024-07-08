#include <stdio.h>
void main()
{ 
       int side1,side2,side3;
       /* input the sides of triangle*/
       printf ("\n enter the value of triangle");
       scanf (" %d %d %d",&side1,&side2,&side3);
       if (side1==side2 & side2==side3)
    {
       /* if all sides are equal*/
       printf ("\n equilateral triangle");
    }
       else if (side1==side2||side1==side3||side2==side3)
    {
       /* if any two sides are equal*/
       printf ("\n isosceles triangle");
    }
    else 
    {
       /* none of the sides are equal*/
     printf ("\n scalene triangle");
    }
    getch();
}
