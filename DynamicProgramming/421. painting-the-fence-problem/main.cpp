#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int add(int a, int b) {
	return (a % MOD + b % MOD) % MOD;
}

int mul(int a, int b) {
	return ((a % MOD)* 1LL * (b % MOD)) % MOD;
}

int solve(int n, int k) {
	if(n == 1)
		return k;

	if(n == 2)
		return add(k, mul(k, k-1));

	int res = add(mul(solve(n-2, k), k-1), mul(solve(n-1, k), k-1));
	return res;
}

int solveMem(int n, int k, vector<int> &dp) {
	if(n == 1)
		return k;
	if(n == 2)
		return add(k, mul(k, k-1));

	// After base case.
	if(dp[n] != -1)
		return dp[n];

	dp[n] = add(mul(solveMem(n-2, k, dp), k-1), mul(solveMem(n-1, k, dp), k-1));
	return dp[n];
}

int solveTab(int n, int k) {
	vector<int> dp(n+1, 0);

	dp[1] = k;
	dp[2] = add(k, mul(k, k-1));

	for(int i = 3; i <= n; i++) {
		dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
	}

	return dp[n];
}

int solveTabSO(int n, int k) {
	int prev2 = k;
	int prev1 = add(k, mul(k, k-1));

	for(int i = 3; i <= n; i++) {
		int ans = add(mul(prev2, k-1), mul(prev1, k-1));

		prev2 = prev1;
		prev1 = ans;
	}

	return prev1;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, k;
	cin >> n >> k;

	cout << solve(n, k) << endl;

	vector<int> dp(n+1, -1);
	cout << solveMem(n, k, dp) << endl;

	cout << solveTab(n, k) << endl;

	return 0;
}