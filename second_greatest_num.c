#include <stdio.h>
int main()
{
    int num1, num2, num3, num4;
    int tmp1, tmp2;
    printf("\n This program prints the second greatest number :");

    printf("\n Enter the first Number :");
    scanf("%d", &num1);
    printf("\n Enter the second Number :");
    scanf("%d", &num2);
    printf("\n Enter the third Number :");
    scanf("%d", &num3);
    printf("\n Enter the fourth Number :");
    scanf("%d", &num4);

    if (num2>num1)
    {
        tmp1 = num2;
    }
    else
    {
        tmp1 = num1;
    }

    if (num4>num3)
    {
        tmp2 = num4;
    }
    else
    {
        tmp2 = num3;
    }
    if (tmp2 > tmp1)
    {
        printf ("The second greatest value is: %d", tmp1);
    }
    else
    {
        printf("The second greatest value is: %d", tmp2);
    }
    return 0;
}




