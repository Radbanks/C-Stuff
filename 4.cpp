#include <iostream>
#include <climits>
using namespace std;

void D_and_C(int arr[], int l, int r, int &min, int &max)
{

 
    if(l==r)                    
    {
        if (max < arr[l]) 
        {           
            max = arr[l];
        }
        if (min > arr[r]) 
        {          
            min = arr[r];
        }
        return;
    }

 
    if (r-l == 1)                
    {
        if (arr[l] < arr[r])      
        {
            if (min > arr[l]) 
            {       
                min = arr[l];
            }
 
            if (max < arr[r]) 
            {      
                max = arr[r];
            }
        }
        else 
        {
            if (min > arr[r]) 
            {     
                min = arr[r];
            }
            if (max < arr[l]) 
            {      
                max = arr[l];
            }
        }
        return;
    }
 
    int mid = (l + r) / 2;
    D_and_C(arr, l, mid, min, max);
    D_and_C(arr, mid + 1, r, min, max);
}
 
int main()
{
    int arr[30],n;
    cout<<"\nEnter the BP of Patient: ";
    cout<<"\nEnter n : ";
    cin>>n;
    for(int i = 0; i < n ; i++)
    {
        cout<<"\nBP ["<<i+1<<"]:";
        cin>>arr[i];
        cout<<"\t";
    }
    int max=INT_MIN, min=INT_MAX;
    D_and_C(arr, 0, n - 1, min, max);
    cout <<"\n[The minimum Blood Pressure is "<<min<<" bpm]";
    cout <<"\n[The maximum Blood Pressure is "<<max<<" bpm]";
    return 0;
}