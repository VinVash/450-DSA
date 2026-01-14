#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b, int i, int j) {
    if(i == a.size())
        return 0;
    if(j == b.size())
        return 0;
    
    int ans = 0;
    if(a[i] == b[j])
        ans = 1 + solve(a, b, i+1, j+1);
    else
        ans = max(solve(a, b, i+1, j), solve(a, b, i, j+1));
    
    return ans;
}

int solveMem(string a, string b, int i, int j, vector<vector<int>> &dp) {
    if(i == a.size())
        return 0;
    if(j == b.size())
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int ans = 0;
    if(a[i] == b[j])
        ans = 1 + solveMem(a, b, i+1, j+1, dp);
    else
        ans = max(solveMem(a, b, i+1, j, dp), solveMem(a, b, i, j+1, dp));
    
    dp[i][j] = ans;
    return dp[i][j];
}

int solveTab(string a, string b) {
    int n = a.size(), m = b.size();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            int ans = 0;
            if(a[i] == b[j]) {
                ans = 1 + dp[i+1][j+1];
            } else {
                ans = max(dp[i+1][j], dp[i][j+1]);
            }
            dp[i][j] = ans;
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