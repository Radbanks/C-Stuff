#include<iostream>
using namespace std;
int count=0;

int PWC(int Day[], int lt,int rt, int N)
{
	int mid=lt+ (rt-lt)/ 2;
	if ((mid == 0 || Day[mid-1] <= Day[mid]) && (mid == N-1 || Day[mid+1] <= Day[mid]))
	{	
	    count++;
        return mid;
    }
    
    count++;
    
	if(mid>0 && Day[mid-1] > Day[mid])
	{
	    count++;
        return PWC(Day,lt,(mid-1),N);
    }
    
    count++;
    count++;
    return PWC(Day,(mid+1),rt,N);
}


int Peak(int Day[], int N)
{
	return PWC(Day,0,N - 1,N);
}


int main()
{
	int Day[30],N;
    cout<<"\nEnter the weather(TEMP) of Patient : ";
    cout<<"\nEnter the number of recorded days : ";
    cin>>N;
    for(int i = 0; i<N ; i++)
    {
        cout<<"\nDAY--->["<<i+1<<"] :";
        cin>>Day[i];
        cout<<"\t";
    }
	cout<<"\nDay of highest temperature is :  "<<Peak(Day, N)+1;
    cout<<"\nNo of comparisons : "<<count;
	return 0;
}
