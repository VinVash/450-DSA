class Solution {
public:
    int solveRec(int x, int y, int m, int n) {
        if(x >= m || y >= n)
            return 0;
        
        if(x == m-1 && y == n-1)
            return 1; // 1 solution found.
        
        return solveRec(x+1, y, m, n) + solveRec(x, y+1, m, n);
    }
    
    int solveMem(int x, int y, int m, int n, vector<vector<int>> &dp) {
        if(x >= m || y >= n)
            return 0;
        
        if(x == m-1 && y == n-1)
            return 1; // 1 solution found.
        
        if(dp[x][y] != -1)
            return dp[x][y];
        
        return dp[x][y] = solveMem(x+1, y, m, n, dp) + solveMem(x, y+1, m, n, dp);
    }
    
    int uniquePaths(int m, int n) {
        
        // int ans = solveRec(0, 0, m, n);
        
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // int ans = solveMem(0, 0, m, n, dp);
        
        // int ans = solveTab(m, n);
        
        int N = n + m -2;
        int R = m - 1;
        double res = 1;
        
        for(int i = 1; i <= R; i++) {
            res = res * (N - R + i) / i;
        }

        // return ans;
        
        return (int)res;
    }
};