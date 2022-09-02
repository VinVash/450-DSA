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

int solveTab(int l, int p, int q, int r) {
    vector<int> dp(l+1, -1);
    dp[0] = 0;

    for (int i = 0; i <= l; i++) {

        // if certain length is not possible
        if (dp[i] == -1)
            continue;

        if (i + p <= l)
            dp[i + p] = max(dp[i + p], dp[i] + 1);

        if (i + q <= l)
            dp[i + q] = max(dp[i + q], dp[i] + 1);

        if (i + r <= l)
            dp[i + r] = max(dp[i + r], dp[i] + 1);
    }

    if (dp[l] == -1) {
        dp[l] = 0;
    }
    // return value corresponding to length l
    return dp[l];
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