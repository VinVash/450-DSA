#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> cost, int i) {
    if(i == cost.size())
        return 0;
    if(i > cost.size())
        return 0;

    return cost[i] + min(solve(cost, i+1), solve(cost, i+2));
}

int solveMem(vector<int> cost, int i, vector<int>& dp) {

    if(i == cost.size())
        return 0;
    if(i > cost.size())
        return 0;

    if(dp[i] != -1)
        return dp[i];

    dp[i] = cost[i] + min(solveMem(cost, i+1, dp), solveMem(cost, i+2, dp));
    return dp[i];
}

int solveTab(vector<int> cost) {
    int n = cost.size();
    vector<int> dp(n+2, 0);
    dp[n] = 0;
    dp[n+1] = 0;

    for(int i = n-1; i >= 0; i--) {
        dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
    }

    return min(dp[0], dp[1]);
}

int solveTab2(vector<int> cost) {
    int n = cost.size();
    int prev = 0;
    int next = 0;

    for(int i = n-1; i >= 0; i--) {
        int curr = cost[i] + min(prev, next);

        prev = next;
        next = curr;
    }

    return min(prev, next);
}

int minCostClimbingStairs(vector<int>& cost) {
    
    int n = cost.size();

    // int ans = min(solve(cost, 0), solve(cost, 1));

    // vector<int> dp(n+1, -1);
    // int ans = min(solveMem(cost, 0, dp), solveMem(cost, 1, dp));

    int ans = solveTab(cost);

    return ans;
    
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}