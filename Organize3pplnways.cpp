// C++ program to find the number
// of ways to distribute N item
// among three people such
// that one person always gets
// the maximum value

#include <bits/stdc++.h>
using namespace std;

// Function to find the number
// of ways to distribute N
// items among 3 people
int countWays(int N)
{
	// No distribution
	// possible
	if (N < 4)
		return 0;

	// Total number of ways to
	// distribute N items
	// among 3 people
	int ans = ((N - 1) * (N
						- 2))
			/ 2;

	// Store the number of
	// distributions which
	// are not possible
	int s = 0;

	for (int i = 2; i <= N - 3;
		i++) {
		for (int j = 1; j < i;
			j++) {

			// Count possibilities
			// of two persons
			// receiving the
			// maximum
			if (N == 2 * i + j)
				s++;
		}
	}

	// If N is divisible by 3
	if (N % 3 == 0)
		s = 3 * s + 1;

	else
		s = 3 * s;

	// Return the final
	// count of ways
	// to distribute
	return ans - s;
}

// Driver Code
int main()
{
	int N = 10;
	cout << countWays(N);
	return 0;
}
