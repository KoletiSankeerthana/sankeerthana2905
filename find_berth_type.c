// find_berth_type.c
#include <stdio.h>
int main()
{
    int seat_num = 0;
    printf("\n Provide the seat number as input:");
    scanf("%d", &seat_num);
    printf(" Provided seat number is: %d", seat_num);
    if ( seat_num > 72 || seat_num < 0)
    {
        printf ("\n invalid input");
        return 0;
    }
    // find reminder of the seat_num by 8
    int reminder = seat_num % 8;
    printf("\n Reminder :%d", reminder);

    if (reminder == 0)
    {
        printf("\n Seat Number is Side Upper Berth");
    }
    else if (reminder == 1 || reminder == 3)
    {
        printf("\n Seat Number is Lower Berth");
    }
    else if ( reminder == 2 || reminder == 5)
    {
        printf("\n seat number is middle berth");
    }
    else if ( reminder == 3 || reminder == 6)
    {
        printf("\n seat number is upper berth");
    }
    else if ( reminder == 7)
    {
        printf("\n seat number is side lower");
    }
    

return (0);
}