#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &nums, int target) {
	// base case.
	if(target < 0)
		return 0;
	if(target == 0)
		return 1;

	int ans = 0;
	for(int i = 0; i < nums.size(); i++) {	
		ans += solveRec(nums, target - nums[i]);
	}

	return ans;
}

int solveMem(vector<int> &nums, int target, vector<int> &dp) {
	// base case.
	if(target < 0)
		return 0;
	if(target == 0)
		return 1;

	if(dp[target] != -1)
		return dp[target];

	int ans = 0;
	for(int i = 0; i < nums.size(); i++) {	
		ans += solveRec(nums, target - nums[i]);
	}
	dp[target] = ans;
	return dp[target];
}

int solveTab(vector<int> &nums, int target) {
	vector<int> dp(target+1, 0);
	dp[0] = 1;

	// traversing from 1 to target.
	for(int i = 1; i <= target; i++) {

		// traversing on nums vector.
		int ans = 0;
		for(int j = 0; j < nums.size(); j++) {
			if(i - nums[j] >= 0)
				ans += dp[i - nums[j]];
		}
		dp[i] = ans;
	}

	return dp[target];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> num {1, 2, 5};
	int target = 5;

	cout << solveRec(num, target) << endl;

	vector<int> dp(target+1, -1);
	cout << solveMem(num, target, dp) << endl;

	cout << solveTab(num, target) << endl;

	return 0;
}