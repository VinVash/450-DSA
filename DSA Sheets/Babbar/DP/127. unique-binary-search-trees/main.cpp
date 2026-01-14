#include <bits/stdc++.h>
using namespace std;

// The answer to this problem is simply the catalan number.

int solve(int n) {
	if(n <= 1)
		return 1;

	int ans = 0;

	// Taking each i as root node.
	for(int i = 1; i <= n; i++) {
		ans += solve(i-1) * solve(n-i);
	}

	return ans;
}

int solveMem(int n, vector<int>& dp) {
	if(n <= 1)
		return 1;

	if(dp[n] != -1)
		return dp[n];

	int ans = 0;

	// Taking each i as root node.
	for(int i = 1; i <= n; i++) {
		ans += solveMem(i-1, dp) * solveMem(n-i, dp);
	}

	return dp[n] = ans;
}

int solveTab(int n) {
	vector<int> dp(n+1, 0);

	dp[0] = dp[1] = 1;

	// i -> represents the no. of nodes. (recursive call)
	for(int i = 2; i <= n; i++) {

		int ans = 0;
		// j -> represents the root node.
		for(int j = 1; j <= i; j++) {
			ans += dp[j-1] * dp[i-j];
		}

		dp[i] = ans;
	}

	return dp[n];
}

// The answer to this problem is simply the catalan number.

int numTrees(int n) {
	// int ans = solve(n);

	vector<int> dp(n+1, -1);
	int ans = solveMem(n, dp);

	return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}