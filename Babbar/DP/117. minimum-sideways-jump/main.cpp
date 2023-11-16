#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &obstacles, int currlane, int currpos) {
	// base case.
	int n = obstacles.size()-1;
	if(currpos == n)
		return 0;

	if(obstacles[currpos+1] != currlane)
		return solveRec(obstacles, currlane, currpos+1);
	else {
		// sideways jump.
		int res = INT_MAX;
		for(int i=1; i <= 3; i++) {
			if(i != currlane && obstacles[currpos] != i) {
				res = min(res, 1 + solveRec(obstacles, i, currpos));
			}
		}
		return res;
	}
}

// Memoization -> top-down.
int solveMem(vector<int> &obstacles, int currlane, int currpos, vector<vector<int>> &dp) {
	// base case.
	int n = obstacles.size();
	if(currpos == n)
		return 0;

	if(dp[currlane][currpos] != -1)
		return dp[currlane][currpos];

	if(obstacles[currpos+1] != currlane)
		return solveRec(obstacles, currlane, currpos+1);
	else {
		// sideways jump.
		int res = 1e9;
		for(int i=1; i <= 3; i++) {
			if(i != currlane && obstacles[currpos] != i) {
				res = min(res, 1 + solveRec(obstacles, i, currpos+1));
			}
		}
		dp[currlane][currpos] = res;
		return dp[currlane][currpos];
	}
}

// Tabulation -> bottom-up.
int solveTab(vector<int> &obstacles) {
	int n = obstacles.size()-1;
	vector<vector<int>> dp(4, vector<int>(n+1, 1e9));

	dp[0][n] = 0;
	dp[1][n] = 0;
	dp[2][n] = 0;
	dp[3][n] = 0;

	// First, we will process a full step / index / position, rather than processing a full lane first.
	// That's why outer for loop is for currpos, and inner is for currlane.
	for(int currpos=n-1; currpos >= 0; currpos--) {
		for(int currlane=1; currlane <= 3; currlane++) {

			if(obstacles[currpos+1] != currlane)
				dp[currlane][currpos] = dp[currlane][currpos+1];
			else {
				// sideways jump.
				int res = INT_MAX;
				for(int i=1; i <= 3; i++) {
					if(i != currlane && obstacles[currpos] != i) {
						res = min(res, 1 + dp[i][currpos+1]);
					}
				}
				dp[currlane][currpos] = res;
			}
		}
	}
	return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}

int solveTabSO(vector<int> &obstacles) {
	int n = obstacles.size()-1;

	vector<int> curr(4, INT_MAX);
	vector<int> next(4, INT_MAX);

	next[0] = 0;
	next[1] = 0;
	next[2] = 0;
	next[3] = 0;

	for(int currpos=n-1; currpos >= 0; currpos--) {
		for(int currlane=1; currlane <= 3; currlane++) {

			if(obstacles[currpos+1] != currlane)
				curr[currlane] = next[currlane];
			else {
				// sideways jump.
				int res = INT_MAX;
				for(int i=1; i <= 3; i++) {
					if(i != currlane && obstacles[currpos] != i) {
						res = min(res, 1 + next[i]);
					}
				}
				curr[currlane] = res;
			}
		}
		next = curr;
	}
	return min(next[2], min(1 + next[1], 1 + next[3]));
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> obstacles {0, 1, 2, 3, 0};
	int n = obstacles.size();
	
	// cout << solveRec(obstacles, 2, 0) << endl; // since the frog is present in lane 2 initially.

	// vector<vector<int>> dp(4, vector<int>(n, -1));
	// cout << solveMem(obstacles, 2, 0, dp) << endl;

	cout << solveTab(obstacles) << endl;

	cout << solveTabSO(obstacles) << endl;

	return 0;
}