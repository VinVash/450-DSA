#include <bits/stdc++.h>
using namespace std;

int solve(int wt[], int val[], int W, int index) {
    if(index == 0) {
        if(wt[0] <= W)
            return val[0];
        else
            return 0;
    }
    
    int inc = 0, exc = 0;
    if(wt[index] <= W)
        inc = val[index] + solve(wt, val, W - wt[index], index-1);
        
    exc = 0 + solve(wt, val, W, index-1);
    
    return max(inc, exc);
}

int solveMem(int wt[], int val[], int W, int index, vector<vector<int>> &dp) {
    if(index == 0) {
        if(wt[0] <= W)
            return val[0];
        else
            return 0;
    }
    
    if(dp[index][W] != -1)
        return dp[index][W];
    
    int inc = 0, exc = 0;
    if(wt[index] <= W)
        inc = val[index] + solveMem(wt, val, W - wt[index], index-1, dp);
        
    exc = 0 + solveMem(wt, val, W, index-1, dp);
    
    return dp[index][W] = max(inc, exc);
}

int solveTab(int wt[], int val[], int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    
    for(int i = wt[0]; i <= W; i++) {
        if(wt[0] <= W)
            dp[0][i] = val[0];
        else
            dp[0][i] = 0;
    }
    
    for(int index = 1; index < n; index++) {
        for(int w = 0; w <= W; w++) {
            int inc = 0, exc = 0;
            
            if(wt[index] <= w)
                inc = val[index] + dp[index-1][w - wt[index]];
                
            exc = 0 + dp[index-1][w];
            
            dp[index][w] = max(inc, exc);
        }
    }
    
    return dp[n-1][W];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}

