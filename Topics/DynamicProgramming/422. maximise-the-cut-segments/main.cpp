#include <bits/stdc++.h>
using namespace std;

// int dp[10005];
// int func(int n, int x, int y, int z) {
// 	if (n == 0) return 0;

// 	if(dp[n] != -1) return dp[n];

// 	int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;

// 	if(n >= x) op1 = func(n-x, x, y, z);
// 	if(n >= y) op1 = func(n-y, x, y, z);
// 	if(n >= z) op1 = func(n-z, x, y, z);

// 	return dp[n] = 1 + max(op1, max(op2, op3));
// }

int funcTab(int n, int x, int y, int z) {
	int dp[10005];
	dp[0] = 0;

	for(int i = 1; i <= n; i++) {
		int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;

		dp[i] = 1 + max(dp[i-x], max(dp[i-y], dp[i-z]));
	}
	return dp[n];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}