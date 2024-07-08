#include <stdio.h>
void main()
{
  int value1,value2;
  float average=0;
  printf ("\n enter value1,value2");
  scanf ("%d %d",&value1,&value2);
  average=(value1+value2)/2;
  printf ("\n the given value1:%d,value2:%d,average:%f",value1,value2,average);
  getch();
  }
