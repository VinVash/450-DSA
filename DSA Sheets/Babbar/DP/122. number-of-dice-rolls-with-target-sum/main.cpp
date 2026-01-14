#include <bits/stdc++.h>
using namespace std;

int solveRec(int dice, int faces, int target) {
	// base case.
	if(target < 0)
		return 0;
	if(dice == 0 && target != 0)
		return 0;
	if(target == 0 && dice != 0)
		return 0;
	if(dice == 0 && target == 0)
		return 1;

	int ans = 0;
	for(int i=1; i <= faces; i++) {
		ans += solveRec(dice-1, faces, target-i);
	}

	return ans;
}

int solveMem(int dice, int faces, int target, vector<vector<int>> &dp) {
	// base case.
	if(target < 0)
		return 0;
	if(dice == 0 && target != 0)
		return 0;
	if(target == 0 && dice != 0)
		return 0;
	if(dice == 0 && target == 0)
		return 1;

	if(dp[dice][target] != -1)
		return dp[dice][target];

	int ans = 0;
	for(int i=1; i <= faces; i++) {
		ans += solveMem(dice-1, faces, target-i, dp);
	}
	dp[dice][target] = ans;
	return dp[dice][target];
}

int solveTab(int dice, int faces, int target) {
	vector<vector<int>> dp(dice+1, vector<int>(target+1, 0));
	dp[0][0] = 1;

	// starting from d=1 and t=1 because we have already analysed and updated the base case in the dp array where d=0 and t=0.
	for(int d=1; d <= dice; d++) {
		for(int t=1; t <= target; t++) {
			int ans = 0;
			for(int i=1; i <= faces; i++) {
				if(target-i >= 0)
					ans += dp[d-1][t-i];
			}
			dp[d][t] = ans;
		}
	}
	return dp[dice][target];
}

int solveTabSO(int dice, int faces, int target) {
	vector<int> prev(target+1, 0);
	vector<int> curr(target+1, 0);
	prev[0] = 1;

	// starting from d=1 and t=1 because we have already analysed and updated the base case in the dp array where d=0 and t=0.
	for(int d=1; d <= dice; d++) {
		for(int t=1; t <= target; t++) {
			int ans = 0;
			for(int i=1; i <= faces; i++) {
				if(target-i >= 0)
					ans += prev[t-i];
			}
			curr[t] = ans;
		}
		prev = curr;
	}
	return prev[target];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	// int M, N, X;
	// cin >> M >> N >> X;

	// cout << solveRec(N, M, X) << endl;

	// vector<vector<int>> dp(N+1, vector<int>(X+1, -1));
	// cout << solveMem(N, M, X, dp) << endl;

	// cout << solveTab(N, M, X) << endl;

	return 0;
}