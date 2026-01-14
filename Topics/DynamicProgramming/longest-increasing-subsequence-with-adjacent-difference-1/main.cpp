#include <bits/stdc++.h>
using namespace std;

// dp[i] be the length of the longest subsequence (with
// differences one) ending at index i such that arr[i] 
// is the last element of the subsequence.

// Function to find the length of longest subsequence
int longestSubseqWithDiffOne(int arr[], int n) {
	// Initialize the dp[] array with 1 as a
	// single element will be of 1 length
	int dp[n];
	for (int i = 0; i < n; i++)
		dp[i] = 1;

	// Start traversing the given array
	for (int i = 1; i < n; i++) {
		// Compare with all the previous elements
		for (int j = 0; j < i; j++) {
			// If the element is consecutive then
			// consider this subsequence and update
			// dp[i] if required.
			if ((arr[i] == arr[j] + 1) || (arr[i] == arr[j] - 1))

				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	// Longest length will be the maximum value
	// of dp array.
	int result = 1;
	for (int i = 0; i < n; i++)
		if (result < dp[i])
			result = dp[i];
	return result;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	nt arr[] = { 1, 2, 3, 4, 5, 3, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << longestSubseqWithDiffOne(arr, n);

	return 0;
}