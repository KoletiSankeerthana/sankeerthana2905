#include <stdio.h>
int main()
{
    int seat_num = 0;
    printf("\n provide seat number as input :");
    scanf("%d", &seat_num);
    printf("\n provided seat number = %d", seat_num);
    if (seat_num > 54 || seat_num < 0)
    {
        printf("\n invalid input");
        return 0;
    }
    // find reminder of the seat_num by 6
    int reminder = seat_num % 6;
    printf("\n Reminder :%d", reminder);

    if (reminder == 2 || reminder == 4)
    {
        printf("\n Seat Number is  Upper Berth");
    }
    else if (reminder == 5|| reminder == 3)
    {
        printf("\n Seat Number is Lower Berth");
    }

    else if (reminder ==0)
    {
        printf("\n seat number is  side upper berth");
    }
    else if (reminder == 1)
    {
        printf("\n seat number is side lower berth");
    }
    return (0);
}
