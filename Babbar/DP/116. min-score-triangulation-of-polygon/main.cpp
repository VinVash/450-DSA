#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &v, int i, int j) {
	// base case.
	if(i+1 == j) {
		return 0;
	}

	int ans = INT_MAX;
	for(int k = i+1; k < j; k++) {
		ans = min(ans, v[i]*v[j]*v[k] + solveRec(v, i, k) + solveRec(v, k, j));
	}
	return ans;
}

int solveMem(vector<int> &v, int i, int j, vector<vector<int>> &dp) {
	// base case.
	if(i+1 == j) {
		return 0;
	}

	if(dp[i][j] != -1)
		return dp[i][j];

	int ans = INT_MAX;
	for(int k = i+1; k < j; k++) {
		ans = min(ans, v[i]*v[j]*v[k] + solveMem(v, i, k, dp) + solveMem(v, k, j, dp));
	}
	dp[i][j] = ans;
	return dp[i][j];
}

int solveTab(vector<int> &v) {
	int n = v.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));

	for(int i=n-1; i >= 0; i--) {
		for(int j = i+2; j < n; j++) {
			int ans = INT_MAX;
			for(int k = i+1; k < j; k++) {
				ans = min(ans, v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
			}
			dp[i][j] = ans;
		}
	}

	return dp[0][n-1];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	// vector<int> values {...........};
	// int n = values.size();
	// cout << solveRec(values, 0, n-1) << endl;

	// vector<vector<int>> dp(n, vector<int>(n, -1));
	// cout << solveMem(values, 0, n-1, dp) << endl;

	// cout << solveTab(values) << endl;

	return 0;
}