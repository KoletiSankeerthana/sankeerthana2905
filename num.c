#include <stdio.h>
int main()
{
  int num1,num2,num3,num4;
  printf("\n enter any four value");
  scanf("%d%d%d%d", &num1,&num2,&num3,&num4);
  if (num1>num2 & num1>num3 & num1>num4)
  {
    printf("\n num1 is greater");
  }
  else if (num2>num1 & num2>num3 & num2>num4)
  {
    printf("\n num2 is greater");
  }
  else if (num3>num1 & num3>num2 & num3>num4)
  {
    printf("\n num3 is greater");
  }
  else
  {
    printf("\n num4 is greater");
  }
  return 0;
}