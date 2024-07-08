#include <stdio.h>
#define PI 3.1415
#define circlearea(r) (PI*r*r)
int main()
{
	float radius,area;
	printf("\n enter the radius=");
	scanf("%f",&radius);
	area=circlearea(radius);
	printf("\n area=%f",area);
	return 0;
}
