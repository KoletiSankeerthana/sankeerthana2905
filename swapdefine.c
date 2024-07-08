#include <stdio.h>
#define SWAP(x,y){printf("SWAP(%d,%d) MACRO\n",x,y);\
                                             int temp;temp=a;a=b;b=temp;}
  int main()
  {
  int a=5,b=10;
  printf ("\n before swap a=%d,b=%d",a,b);
  SWAP(a,b);
  printf("\n after swap a=%d,b=%d",a,b);
  return 0;                                                  


}
