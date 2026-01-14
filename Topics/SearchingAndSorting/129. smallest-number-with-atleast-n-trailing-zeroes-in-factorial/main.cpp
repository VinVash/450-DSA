#include<bits/stdc++.h>
using namespace std;

// Returns true if number's factorial contains at least n trailing zero else false.
bool check (int p, int n) {
	int temp = p, count = 0, f = 5;
	
	while (f <= temp) {
		count += temp/f;
		f = f*5; // automatically divides by 5, 25, 125, ...
	}

	return (count >= n);
}

// Returns smallest number whose factorial contains at least n trailing zeroes.
int findNum (int n) {
	// If n equal to 1, return 5.
	// since 5! = 120.
	if (n == 1)
		return 5;

	// Initialising low and high for binary search.
	int low = 0;
	int high = 5 * n;

	cout << low << " " << high << endl;

	// Binary Search.
	while (low < high) {
		int mid = (low + high) >> 1; // another way of dividing by 2.

		// Checking if mid's factorial contains n trailing zeroes.
		if (check(mid, n))
			high = mid;
		else
			low = mid+1;
	}

	return low;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n = 45;
    cout << findNum(n) << endl;

	return 0;
}
