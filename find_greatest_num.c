// find_second_greatest_num.c

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

    if (num1> num2)
    {
        tmp1 = num2;
    }
    else
    {
        tmp1 = num2;
    }

    if (num3 > num4)
    {
        tmp2 = num3;
    }
    else
    {
        tmp2 = num4;
    }

    if (tmp2 > tmp1)
    {
        printf ("The largest value is: %d", tmp2 );
    }
    else
    {
        printf("The largest value is :%d", tmp1);
    }

    return 0;
}
