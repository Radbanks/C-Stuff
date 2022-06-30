#include <iostream>
using namespace std;

void MM(int m1, int m2, int A[][2], int n1, int n2,int B[][2])
{
	int x, i, j;
	int FINAL[m1][n2];
	for (i=0;i<m1;i++)
	{
		for (j=0;j<n2;j++)
		{
			FINAL[i][j] = 0;
			for (x=0;x<m2;x++)
			{
				*(*(FINAL+i)+j) += *(*(A+i)+x)* *(*(B+x)+j);
			}
		}
	}
	cout<<"\nThe MULTIPLIED array is:\n";
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			cout<<*(*(FINAL + i) + j)<<" ";
		}
		cout << "\n";
	}
}

int main()
{
	int A[][2] = {{1,2},{3,4}};
	int B[][2] = {{5,6},{7,8}};
	int m1=2,m2=2,n1=2,n2=2;
	MM(m1,m2,A,n1,n2,B);
	return 0;
}
