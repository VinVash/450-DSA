#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// Exponential
long long int solveRec(int n) {
	// base cases.
	if(n == 1)
		return 0;

	if(n == 2)
		return 1;

	int res = ((n-1) % MOD * ((solveRec(n-1) % MOD) + (solveRec(n-2) % MOD)) % MOD);

	return res;
}

long long int solveMem(int n, vector<long long int> &dp) {
	// base cases.
	if(n == 1)
		return 0;
	if(n == 2)
		return 1;

	if(dp[n] != -1)
		return dp[n];

	dp[n] = ((n-1) % MOD * ((solveMem(n-1, dp) % MOD) + (solveMem(n-2, dp) % MOD)) % MOD);
	return dp[n];
}

long long int solveTab(int n) {
	vector<long long int> dp(n+1, 0);
	dp[1] = 0;
	dp[2] = 1;

	for(int i = 3; i <= n; i++) {
		long long int first = dp[i-1] % MOD;
		long long int second = dp[i-2] % MOD;
		long long int sum = (first + second) % MOD;

		long long int res = ((i-1) * sum) % MOD;
		dp[i] = res;
	}

	return dp[n];
}

long long int solveTabSO(int n) {
	
	long long int prev2 = 0;
	long long int prev1 = 1;

	for(int i = 3; i <= n; i++) {
		long long int first = prev1 % MOD;
		long long int second = prev2 % MOD;
		long long int sum = (first + second) % MOD;

		long long int res = ((i-1) * sum) % MOD;

		prev2 = prev1;
		prev1 = res;
	}

	return prev1;;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;

	cout << solveRec(n) << endl;
	cout << endl;

	vector<long long int> dp(n+1, -1);
	cout << solveMem(n, dp) << endl;
	cout << endl;

	cout << solveTab(n) << endl;
	cout << endl;

	cout << solveTabSO(n) << endl;

	return 0;
}