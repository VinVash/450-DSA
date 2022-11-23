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

int solveTab(vector<int> &nums, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int curr = n-1; curr >= 0; curr--) {
        for(int prev = curr-1; prev >= -1; prev--) {
            int inc = 0, exc = 0;
            
            if(prev == -1 || nums[curr] > nums[prev]) {
                inc = 1 + solveMem(nums, n, curr+1, curr, dp);
            }

            exc = 0 + solveMem(nums, n, curr+1, prev, dp);
            
            dp[curr][prev+1] = max(inc, exc);
        }
    }
    
    return dp[0][0];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}