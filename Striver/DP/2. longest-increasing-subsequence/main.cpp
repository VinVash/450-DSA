#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int n, int curr, int prev) {
    if(curr == n)
        return 0;
    
    int inc = 0, exc = 0;
    if(prev == -1 || nums[curr] > nums[prev]) {
        inc = 1 + solve(nums, n, curr+1, curr);
    }
    
    exc = 0 + solve(nums, n, curr+1, prev);
    
    return max(inc, exc);
}

int solveMem(vector<int> &nums, int n, int curr, int prev, vector<vector<int>> &dp) {
    if(curr == n)
        return 0;
    
    // here +1 because initially prev = -1, hence we  can't access index -1.
    if(dp[curr][prev+1] != -1)
        return dp[curr][prev+1];
    
    int inc = 0, exc = 0;
    if(prev == -1 || nums[curr] > nums[prev]) {
        inc = 1 + solveMem(nums, n, curr+1, curr, dp);
    }
    
    exc = 0 + solveMem(nums, n, curr+1, prev, dp);
    
    dp[curr][prev+1] = max(inc, exc);
    return dp[curr][prev+1];
}

int solveTab(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int curr = n-1; curr >= 0; curr--) {
        for(int prev = curr-1; prev >= -1; prev--) {
            int inc = 0;
            if(prev == -1 || nums[curr] > nums[prev])
                inc = 1 + dp[curr+1][curr+1];

            int exc = dp[curr+1][prev+1];
            
            dp[curr][prev+1] = max(inc, exc);
        }
    }

    return dp[0][0];
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    // int ans = solve(nums, 0, -1);

    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // int ans = solveMem(nums, 0, -1, dp);

    int ans = solveTab(nums);

    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}