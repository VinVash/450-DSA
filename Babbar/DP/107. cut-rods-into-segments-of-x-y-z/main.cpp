#include <bits/stdc++.h>
using namespace std;

int solveRec(int n, int x, int y, int z) {
	// base cases.
	if(n == 0)
		return 0;

	if(n < 0)
		return INT_MIN;

	int a = solveRec(n-x, x, y, z) + 1;
	int b = solveRec(n-y, x, y, z) + 1;
	int c = solveRec(n-z, x, y, z) + 1;

	return max(a, max(b, c));
}

int solveMem(int n, int x, int y, int z, vector<int> &dp) {
	// base cases.
	if(n == 0)
		return 0;

	if(n < 0)
		return INT_MIN;

	if(dp[n] != -1)
		return dp[n];

	int a = solveMem(n-x, x, y, z, dp) + 1;
	int b = solveMem(n-y, x, y, z, dp) + 1;
	int c  = solveMem(n-z, x, y, z, dp) + 1;

	dp[n] = max(a, max(b, c));
	return dp[n];
}

int solveTab(int n, int x, int y, int z) {
	vector<int> dp(n+1, -1);

	dp[0] = 0;

	for(int i = 1; i <= n; i++) {
		if(i - x >= 0 && dp[i-x] != -1)
			dp[i] = max(dp[i], dp[i-x] + 1);

		if(i - y >= 0 && dp[i-x] != -1)
			dp[i] = max(dp[i], dp[i-y] + 1);

		if(i - z >= 0 && dp[i-x] != -1)
			dp[i] = max(dp[i], dp[i-z] + 1);
	}

	if(dp[n] < 0)
		return 0;
	else
		return dp[n];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, x, y, z;
	cin >> n >> x >> y >> z;

	// int res = solveRec(n, x, y, z);

	// vector<int> dp(n+1, -1);
	// int res = solveMem(n, x, y, z, dp);

	int res = solveTab(n, x, y, z);

	if(res < 0)
		cout << 0 << endl;
	else
		cout << res << endl;

	return 0;
}