#include <iostream>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct Location
{
	public:
	int x, y;
};


int CX(const void* A, const void* B)
{
	
	Location *P1 = (Location *)A;
	Location *P2 = (Location *)B;
	return (P1->x - P2->x);

}

int CY(const void* A, const void* B)
{
	
	Location *P1 = (Location *)A;
	Location *P2 = (Location *)B;
	return (P1->y - P2->y);

}

float dist(Location P1, Location P2)
{
	
	return sqrt((P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y));

}

float bruteForce(Location P[], int n)
{
	float min=FLT_MAX;
	for (int i=0; i<n; ++i)
	{	
	    for (int j= i+1 ; j<n; ++j)
		{	
			if (dist(P[i], P[j]) < min)
			{	
				min = dist(P[i], P[j]);
			}
		}
	}
	return min;
}

float smallest_of_two(float x, float y)
{
	if(x<y)
	{
	    return x;
	}
	else
	{
	    return y;
	}
}


float stripClosest(Location S[], int size, float d)
{
	float min = d; 
	qsort(S, size, sizeof(Location), CY);
	for (int i = 0; i < size; ++i)
	{	
		for (int j = i+1; j < size && (S[j].y - S[i].y) < min; ++j)
		{	
			if (dist(S[i],S[j]) < min)
			{	
				min = dist(S[i], S[j]);
			}
		}
	}
	return min;
}

float Closest_2(Location P[], int n)
{
	if (n <= 3)
	{	
		return bruteForce(P, n);
	}

	int mid = n/2;
	Location midPoint = P[mid];
	float dl = Closest_2(P, mid);
	float dr = Closest_2(P + mid, n-mid);
	float d = smallest_of_two(dl, dr);

	Location S[n];
	int j = 0;
	for (int i=0; i<n; i++)
	{	
		if (abs(P[i].x - midPoint.x) < d)
		{	
			S[j] = P[i];
			j++;
		}
	}
	return smallest_of_two(d,stripClosest(S, j, d));
}

float Closest_1(Location P[], int n)
{
	qsort(P, n, sizeof(Location), CX);
	return Closest_2(P, n);
}

int main()
{
	Location P[30];
	int n;
    cout<<"\nEnter the  Boats Location: ";
    cout<<"\n\nEnter number of boats : ";
    cin>>n;
    for(int i=0; i<n ; i++)
    {
        cout<<"\nBoat "<<i+1<<" :";
		cout<<"\n\tx: ";
		cin>>P[i].x;
		cout<<"\ty: ";
		cin>>P[i].y;
        cout<<"\n";
    }
	cout<<"\nThe smallest distance is "<<Closest_1(P, n);
	return 0;
}

