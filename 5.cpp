#include <iostream>
#include <limits.h>
#include <stdio.h>
using namespace std;


int Biggest_(int x, int y) 
{ 
    return (x > y) ? x : y; 
}


int Biggest_(int x, int y, int z) 
{
    return Biggest_(Biggest_(x, y), z); 
}


int max_CS(int arr[], int l, int m, int h)
{
	int sum = 0;
	int ls=INT_MIN;
	for (int i = m; i >= l; i--) 
    {
		sum = sum + arr[i];
		if (sum > ls)
		{	
            ls = sum;
        }
	}
	sum = 0;
	int rs=INT_MIN;
	for (int i = m + 1; i <= h; i++) 
    {
		sum = sum + arr[i];
		if (sum > rs)
		{	
            rs = sum;
        }
	}
	return Biggest_(ls + rs, ls, rs);
}



int max_of_SUB(int arr[], int l, int h)
{
	if (l == h)
		return arr[l];
	int m = (l + h) / 2;
	return Biggest_(max_of_SUB(arr, l, m),max_of_SUB(arr, m + 1, h),max_CS(arr, l, m, h));
}



int main()
{
	int arr[20],n;
    cout<<"\nEnter the  subweather: ";
    cout<<"\nEnter number of weather slots : ";
    cin>>n;
    for(int i = 0; i < n ; i++)
    {
        cout<<"\nTEMP ["<<i+1<<"]: ";
        cin>>arr[i];
        cout<<"\t";
    }
	int max_sum = max_of_SUB(arr, 0, n - 1);
	cout<<"\nMaximum average of subweather sum is "<< max_sum<<"\n";
	return 0;
}
