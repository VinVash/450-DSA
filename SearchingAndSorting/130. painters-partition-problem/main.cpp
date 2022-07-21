#include <bits/stdc++.h>
using namespace std;

// function to calculate sum between two indices in array
int sum(int arr[], int from, int to) {
	int total = 0;
	for (int i = from; i <= to; i++)
		total += arr[i];
	return total;
}

// bottom up tabular dp
int findMax(int arr[], int n, int k) {
	
	// initialize table
	vector<vector<int>> dp(k+1, vector<int>(n+1, 0));

	// base cases
	// k=1
	for (int i = 1; i <= n; i++)
		dp[1][i] = sum(arr, 0, i - 1); // time taken by one painter to paint boards from index 0 to i.

	// n=1
	for (int i = 1; i <= k; i++)
		dp[i][1] = arr[0]; // time taken by all painters to paint one board.

	vector<int> sum(n+1, 0);
 
	// sum from 1 to i elements of arr
	for (int i = 1; i <= n; i++)
	sum[i] = sum[i-1] + arr[i-1];

	for (int i = 1; i <= n; i++)
	dp[1][i] = sum[i];

	// 2 to k partitions (partitions are equal to the no. of painters).
	for (int i = 2; i <= k; i++) {
		// 2 to n boards
		for (int j = 2; j <= n; j++) {

			// track minimum
			int best = INT_MAX;

			// i-1 th separator before position arr[p=1..j]
			for (int p = 1; p <= j; p++)
				best = min(best, max(dp[i - 1][p], sum[j]-sum[p]));

			dp[i][j] = best;
		}
	}

	return dp[k][n];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int arr[] = { 10, 20, 60, 50, 30, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;

	cout << findMax(arr, n, k) << endl;

	return 0;
}
