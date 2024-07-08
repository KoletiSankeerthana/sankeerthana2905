#include <stdio.h>
int sum(int[][3],int,int);
int main()
{
	int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int row=3,column=3,nsum=0;
	nsum=sum(matrix,row,column);
	printf("\n row wise sum=%d",nsum);
	return 0;
}
int sum(int arr[][3],int row,int column)
{
	int sum=0;
	int tempsum=0;
	int r,c;
	for (r=0;r<row;r++)
	{
		for(c=0;c<column;c++)
		{
			tempsum+=arr[r][c];
		}
		sum+=tempsum;
		}
		return sum;
	}
