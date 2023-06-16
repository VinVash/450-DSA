#include <bits/stdc++.h>
using namespace std;

int solveRec(int index, int buy, vector<int> &prices, int limit) {
	
	// base case.
	if(index == prices.size())
		return 0;

	if(limit == 0)
		return 0;

	int profit = 0;
	if(buy) {
		profit = max(-prices[index] + solveRec(index+1, 0, prices, limit), 0 + solveRec(index+1, 1, prices, limit));
	} else {
		profit = max(prices[index] + solveRec(index+1, 1, prices, limit-1), 0 + solveRec(index+1, 0, prices, limit));
	}

	return profit;
}

int solveMem(int index, int buy, vector<int> &prices, int limit, vector<vector<vector<int>>> &dp) {
	
	// base case.
	if(index == prices.size())
		return 0;

	if(limit == 0)
		return 0;

	if(dp[index][buy][limit] != -1)
		return dp[index][buy][limit];

	int profit = 0;
	if(buy) {
		profit = max(-prices[index] + solveMem(index+1, 0, prices, limit, dp), 0 + solveMem(index+1, 1, prices, limit), dp);
	} else {
		profit = max(prices[index] + solveMem(index+1, 1, prices, limit-1, dp), 0 + solveMem(index+1, 0, prices, limit, dp));
	}

	dp[index][buy][limit] = profit;
	return dp[index][buy][limit];
}

int solveTab(vector<int> &prices) {
	int n = prices.size();
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, 0)));

	for(int index = n-1; index >= 0; index--) {
		for(int buy = 0; buy <= 1; buy++) {
			for(limit = 1; limit <= 2; limit++) {
				int profit = 0;
				if(buy) {
					profit = max(-prices[index] + dp[index+1][0][limit], dp[index+1][1][limit]);
				} else {
					profit = max(prices[index] + dp[index+1][1][limit-1], 0 + dp[index+1][0][limit]);
				}

				dp[index][buy][limit] = profit;
			}
		}
	}

	return dp[0][1][2] + 1;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
	cout << solveMem(0, 1, prices, 2, dp);

	return 0;
}