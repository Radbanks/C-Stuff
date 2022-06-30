#include <iostream>
#include <iomanip>

using namespace std;

struct classes
{
    public:
    int l,r;
    int clash;
}A[10];
1
void Assign_clash(int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0; j<n ; j++)
        {
         if( A[i].l==A[j].l && A[i].r==A[j].r)
         {
            A[i].clash++;
         } 
        }  
    }
}

void Clash_check(int n)
{
   for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
         if( A[i].l==A[j].l && A[i].r==A[j].r && A[i].clash>=3)
         {
            cout<<"NO";
            exit(0);
         } 
        }  
    } 
}
int main()
{
    int no_of_classes=3;
    for(int i=0;i<no_of_classes; i++)
    {
        cout<<"\nEnter the classes [l,r]: ";
        cin>>A[i].l>>A[i].r;
    }
    Assign_clash(no_of_classes);
    Clash_check(no_of_classes);
    cout<<"YES";
    return 0;
}