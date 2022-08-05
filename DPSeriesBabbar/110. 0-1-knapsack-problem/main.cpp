#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &weight, vector<int> &value, int index, int W) {
	// base case.
	// if only one item, then just compare its weight with the knapsack capacity.
	if(index == 0) {
		if(weight[0] <= W)
			return value[0];
		else
			return 0;
	}

	int inc, exc;
	if(weight[index] <= W)
		inc = value[index] + solveRec(weight, value, index-1, W - weight[index]);

	exc = 0 + solveRec(weight, value, index-1, W);

	int res = max(inc, exc);
	return res;
}

int solveMem(vector<int> &weight, vector<int> &value, int index, int W, vector<vector<int>> &dp) {
	// base case.
	// if only one item, then just compare its weight with the knapsack capacity.
	if(index == 0) {
		if(weight[0] <= W)
			return value[0];
		else
			return 0;
	}

	if(dp[index][W])
		return dp[index][W];

	int inc, exc;
	if(weight[index] <= W)
		inc = value[index] + solveMem(weight, value, index-1, W - weight[index], dp);

	exc = 0 + solveMem(weight, value, index-1, W, dp);

	dp[index][W] = max(inc, exc);
	return dp[index][W];
}

int solveTab(vector<int> &weight, vector<int> &value, int n, int W) {
	vector<vector<int>> dp(n, vector<int>(W+1, 0));

	for(int i = weight[0]; i <= W; i++) {
		if(weight[0] <= W)
			dp[0][i] = value[0];
		else
			dp[0][i] = 0;
	}

	for(int index = 1; index < n; index++) {
		for(int w = 0; w <= W; w++) {
			int inc, exc;

			if(weight[index] <= w)
				inc = value[index] + dp[index-1][w - weight[index]];

			exc = 0 + dp[index-1][w];

			dp[index][w] = max(inc, exc);
		}
	}

	return dp[n-1][W];
}

int solveTabSO(vector<int> &weight, vector<int> &value, int n, int W) {
	vector<int> prev(W + 1, 0);
	vector<int> curr(W + 1, 0);

	for(int w = weight[0]; w <= W; w++) {
		if(weight[0] <= W)
			prev[w] = value[0];
		else
			prev[w] = 0;
	}

	for(int index = 1; index < n; index++) {
		for(int w = 0; w <= W; w++) {
			int inc, exc;

			if(weight[index] <= w)
				inc = value[index] + prev[w - weight[index]];

			exc = 0 + prev[w];

			curr[w] = max(inc, exc);
		}

		prev = curr;
	}

	return prev[W];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	// cout << solveRec(weight, value, n-1, maxWeight);

	// vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
	// cout << solveMem(weight, value, n-1, maxWeight, dp) << endl;

	return 0;
}