#include <bits/stdc++.h>
using namespace std;

// just keep track whether at any moment, we have the stock or not.
int solveRec(int index, int buy, vector<int> &prices)
{

	// base case.
	if (index == prices.size())
		return 0;

	int profit = 0;
	if (buy)
	{
		profit = max(-prices[index] + solveRec(index + 1, 0, prices), 0 + solveRec(index + 1, 1, prices));
	}
	else
	{
		profit = max(prices[index] + solveRec(index + 1, 1, prices), 0 + solveRec(index + 1, 0, prices));
	}

	return profit;
}

int solveMem(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
	// base case.
	if (index == prices.size())
		return 0;

	if (dp[index][buy] != -1)
		return dp[index][buy];

	int profit = 0;
	if (buy)
	{
		profit = max(-prices[index] + solveMem(index + 1, 0, prices, dp), 0 + solveMem(index + 1, 1, prices, dp));
	}
	else
	{
		profit = max(prices[index] + solveMem(index + 1, 1, prices, dp), 0 + solveMem(index + 1, 0, prices, dp));
	}

	dp[index][buy] = profit;
	return dp[index][buy];
}

// Time: O(N), Space: O(2*N) = O(N)
int solveTab(vector<int> &prices)
{
	int n = prices.size();
	vector<vector<int>> dp(n + 1, vector<int>(2, 0));

	for (int index = n - 1; index >= 0; index--)
	{
		for (int buy = 0; buy <= 1; buy++)
		{

			int profit = 0;
			if (buy)
			{
				profit = max(-prices[index] + solveMem(index + 1, 0, prices, dp), 0 + solveMem(index + 1, 1, prices, dp));
			}
			else
			{
				profit = max(prices[index] + solveMem(index + 1, 1, prices, dp), 0 + solveMem(index + 1, 0, prices, dp));
			}

			dp[index][buy] = profit;
		}
	}
	return dp[0][1];
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> prices{7, 1, 5, 3, 6, 4};
	int n = prices.size();

	cout << solveRec(0, 1, prices) << endl;

	vector<vector<int>> dp(n + 1, vector<int>(2, -1));
	cout << solveMem(0, 1, prices, dp) << endl;

	cout << solveTab(prices) << endl;

	return 0;
}