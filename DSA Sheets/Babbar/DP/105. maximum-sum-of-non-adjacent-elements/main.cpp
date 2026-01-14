#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &nums, int n) {
	if(n < 0)
		return 0;

	if(n == 0)
		return nums[0];

	int inc = solveRec(nums, n-2) + nums[n];
	int exc = solveRec(nums, n-1) + 0;

	return max(inc, exc);
}

int solveMem(vector<int> &nums, int n, vector<int> &dp) {
	if(n < 0)
		return 0;

	if(n == 0)
		return nums[0];

	if(dp[n] != -1)
		return dp[n];

	int inc = solveMem(nums, n-2, dp) + nums[n];
	int exc = solveMem(nums, n-1, dp) + 0;

	dp[n] = max(inc, exc);
	return dp[n];
}

int solveTab(vector<int> &nums) {
	int n = nums.size();
	vector<int> dp(n, 0);

	dp[0] = nums[0];

	for(int i = 1; i < n; i++) {
		int inc = dp[i-2] + nums[i];
		int exc = dp[i-1] + 0;

		dp[i] = max(inc, exc);
	}

	return dp[n-1];
}

int solveTabSO(vector<int> &nums) {
	int n = nums.size();

	int prev2 = 0;
	int prev1 = nums[0];

	for(int i = 1; i < n; i++) {
		int inc = prev2 + nums[i];
		int exc = prev1 + 0;
		int ans = max(inc, exc);

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

    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

	cout << solveRec(nums, n-1) << endl;
	cout << endl;

	vector<int> dp(n, -1);
	cout << solveMem(nums, n-1, dp) << endl;
	cout << endl;

	cout << solveTab(nums) << endl;
	cout << endl;

	cout << solveTabSO(nums) << endl;

	return 0;
}