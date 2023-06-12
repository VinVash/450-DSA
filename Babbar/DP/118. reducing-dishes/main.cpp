#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &satisfaction, int index, int time) {
	// base case.
	if(index == satisfaction.size())
		return 0;

	int include = satisfaction[index] * (time + 1) + solveRec(satisfaction, index+1, time+1);
	int exclude = 0 + solveRec(satisfaction, index+1, time);

	return max(include, exclude);
}

int solveMem(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp) {
	// base case.
	if(index == satisfaction.size())
		return 0;

	if(dp[index][time] != -1)
		return dp[index][time];

	int include = satisfaction[index] * (time + 1) + solveMem(satisfaction, index+1, time+1, dp);
	int exclude = 0 + solveMem(satisfaction, index+1, time, dp);

	dp[index][time] = max(include, exclude);
	return dp[index][time];
}

int solveTab(vector<int> &satisfaction) {
	int n = satisfaction.size();
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

	// Already initialised every element to 0, so need to specifiy base case from solveMem.

	for(int index=n-1; index >= 0; index--) {
		for(int time=index; time >= 0; time--) {
			int include = satisfaction[index] * (time + 1) + dp[index+1][time+1];
			int exclude = 0 + dp[index+1][time];

			dp[index][time] = max(include, exclude);
		}
	}

	return dp[0][0];
}

int solveTabSO(vector<int> &satisfaction) {
	int n = satisfaction.size();
	vector<int> curr(n+1, 0);
	vector<int> next(n+1, 0);

	// Already initialised every element to 0, so need to specifiy base case from solveMem.

	for(int index=n-1; index >= 0; index--) {
		for(int time=index; time >= 0; time--) {
			int include = satisfaction[index] * (time + 1) + next[time+1];
			int exclude = 0 + next[time];

			curr[time] = max(include, exclude);
		}
		next = curr;
	}

	return next[0];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> satisfaction;
	// sort(satisfaction.begin(), satisfaction.end());
	// cout << solveRec(satisfaction, 0, 0) << endl;

	// int n = satisfaction.size();
	// vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	// cout << solveMem(satisfaction, 0, 0, dp) << endl;

	// cout << solveTab(satisfaction) << endl;
	return 0;
}