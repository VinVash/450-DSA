#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b, int i, int j) {
    if(i == a.size())
        return b.size() - j;
    if(j == b.size())
        return a.size() - i;
    
    int ans = 0;
    if(a[i] == b[j]) {
        return solve(a, b, i+1, j+1);
    } else {
//             insert case
        int insertAns = 1 + solve(a, b, i, j+1);
        
//             delete case
        int deleteAns = 1 + solve(a, b, i+1, j);
        
//             replace case
        int replaceAns = 1 + solve(a, b, i+1, j+1);
        
        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    
    return ans;
}

int solveMem(string a, string b, int i, int j, vector<vector<int>> &dp) {
    if(i == a.size())
        return b.size() - j;
    if(j == b.size())
        return a.size() - i;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int ans = 0;
    if(a[i] == b[j]) {
        return solveMem(a, b, i+1, j+1, dp);
    } else {
//             insert case
        int insertAns = 1 + solveMem(a, b, i, j+1, dp);
        
//             delete case
        int deleteAns = 1 + solveMem(a, b, i+1, j, dp);
        
//             replace case
        int replaceAns = 1 + solveMem(a, b, i+1, j+1, dp);
        
        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    
    return dp[i][j] = ans;
}

int solveTab(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int j = 0; j < b.size(); j++) {
        dp[a.size()][j] = b.size() - j;
    }
    
    for(int i = 0; i < a.size(); i++) {
        dp[i][b.size()] = a.size() - i;
    }
    
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            int ans = 0;
            
            if(a[i] == b[j]) {
                ans = dp[i+1][j+1];
            } else {
    //             insert case
                int insertAns = 1 + dp[i][j+1];

    //             delete case
                int deleteAns = 1 + dp[i+1][j];

    //             replace case
                int replaceAns = 1 + dp[i+1][j+1];

                ans = min(insertAns, min(deleteAns, replaceAns));
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