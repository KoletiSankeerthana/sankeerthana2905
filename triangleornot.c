#include <stdio.h>

int main() 
{
int side1, side2, side3,sum;

    printf("Enter three sides of a triangle:\n");
    scanf("%d %d %d", &side1, &side2, &side3);
    sum=side1+side2+side3;
    if (sum==180&&side1!=0&&side2!=0&& side3!=0) 
	{
        printf("The given sides can form a valid triangle.\n");
    } else {
        printf("The given sides cannot form a valid triangle.\n");
    }
return 0;
}
