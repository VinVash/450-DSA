#include <bits/stdc++.h>
using namespace std;

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

int solveRec(vector<int> &nums, int n) {
    if(n == 0)
        return nums[0];
    if(n < 0)
        return 0;
    
    int inc = nums[n] + solveRec(nums, n-2);
    int exc = 0 + solveRec(nums, n-1);
    
    return max(inc, exc);
}

int solveMem(vector<int> &nums, int n, vector<int> &dp) {
    if(n == 0)
        return nums[0];
    if(n < 0)
        return 0;
    
    if(dp[n] != -1)
        return dp[n];
    
    int inc = nums[n] + solveMem(nums, n-2, dp);
    int exc = 0 + solveMem(nums, n-1, dp);
    
    dp[n] = max(inc, exc);
    return dp[n];
}

int solveTab(vector<int> &nums, int n) {
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    
    for(int i = 1; i < n; i++) {
        int inc = nums[i];
        if(i-2 >= 0)
            inc += dp[i-2];
        int exc = 0 + dp[i-1];

        dp[i] = max(inc, exc);
    }
    
    return dp[n-1];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    // return solveRec(nums, n-1);
    
    // vector<int> dp(n+1, -1);
    // return solveMem(nums, n-1, dp);
    
    return solveTab(nums, n);
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

	vector<int> v; // for passing in the function calls.

	v.assign(nums.begin(), nums.end()-1);
	int res1 = solveTabSO(v);

	v.assign(nums.begin()+1, nums.end());
	int res2 = solveTabSO(v);

	cout << max(res1, res2) << endl;

	return 0;
}