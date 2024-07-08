#include <stdio.h>
float iaverage(int[],int);
float faverage(float[],int);
int main()
{
	int numelem=3;
	int idigit[3]={5,6,7};
	float fdigit[3]={3.4,5.6,2.8};
	float average_1=0;
	float average_2=0;
	
	average_1=iaverage(idigit,numelem);
	average_2=faverage(fdigit,numelem);
	printf("\n iaverage=%f,faverage=%f",average_1,average_2);
	return 0;

}
float iaverage(int arr[],int n)
{
	float avg=0;
	int i;
	for(i=0;i<n;i++)
	{
        avg+=arr[i];
		avg=avg/3;
	}
		return avg;
		
	}
	float faverage(float arr[],int n)
	{
		float avg=0;
		int i;
		for(i=0;i<n;i++)
		{
		
			avg+=arr[i];
			avg=avg/3;
		}
			return avg;
	     
	}
