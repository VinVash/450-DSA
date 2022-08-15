#include <bits/stdc++.h>
using namespace std;

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


	return 0;
}