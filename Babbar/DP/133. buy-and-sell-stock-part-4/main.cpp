#include <bits/stdc++.h>
using namespace std;

int solveRec(int index, int operationNo, int k, vector<int> &prices) {
	if(index == prices.size())
		return 0;

	if(operationNo == 2*k)
		return 0;

	int profit = 0;
	if(operationNo % 2 == 0) {
		// buy allowed
		int buyKaro = -prices[index] + solveRec(index+1, operationNo+1, k, prices);
		int skipKaro = 0 + solveRec(index+1, operationNo, k, prices);

		profit = max(buyKaro, skipKaro);
	} else {
		int sellKaro = prices[index] + solveRec(index+1, operationNo+1, k, prices);
		int skipKaro = 0 + solveRec(index+1, operationNo, k, prices);

		profit = max(sellKaro, skipKaro);
	}

	return profit;
}

int solveMem(int index, int operationNo, int k, vector<int> &prices, vector<vector<int>> &dp) {
	if(index == prices.size())
		return 0;

	if(operationNo == 2*k)
		return 0;

	if(dp[index][operationNo] != -1) {
		return dp[index][operationNo];
	}

	int profit = 0;
	if(operationNo % 2 == 0) {
		// buy allowed
		int buyKaro = -prices[index] + solveMem(index+1, operationNo+1, k, prices, dp);
		int skipKaro = 0 + solveMem(index+1, operationNo, k, prices, dp);

		profit = max(buyKaro, skipKaro);
	} else {
		int sellKaro = prices[index] + solveMem(index+1, operationNo+1, k, prices, dp);
		int skipKaro = 0 + solveMem(index+1, operationNo, k, prices, dp);

		profit = max(sellKaro, skipKaro);
	}

	dp[index][operationNo] = profit;
	return dp[index][operationNo];
}

int solveTab(int k, vector<int> &prices) {
	int n = prices.size();
	vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

	for(int index = n-1; index >= 0; index--) {
		for(int operationNo = 2*k-1; operationNo >= 0; operationNo--) {

			int profit = 0;
			if(operationNo % 2 == 0) {
				// buy allowed
				int buyKaro = -prices[index] + dp[index+1][operationNo+1];
				int skipKaro = 0 + dp[index+1][operationNo];

				profit = max(buyKaro, skipKaro);
			} else {
				int sellKaro = prices[index] + dp[index+1][operationNo+1];
				int skipKaro = 0 + dp[index+1][operationNo];

				profit = max(sellKaro, skipKaro);
			}

			dp[index][operationNo] = profit;
		} 
	}	
	return dp[0][0];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	// cout << solveRec(0, 0, k, prices) << endl;

    // int n = prices.size();
	// vector<vector<int>> dp(n, vector<int>(2*k, -1));
	// cout << solveMem(0, 0, k, prices, dp) << endl;

	// cout << solveTab(k, prices) << endl;

	return 0;
}