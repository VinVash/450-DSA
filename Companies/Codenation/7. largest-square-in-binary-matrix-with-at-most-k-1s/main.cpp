#include <bits/stdc++.h>
using namespace std;

vector<int> largestSquare(vector<vector<int>> M, int r, int c, int k, int Q, int q_i[], int q_j[]) {
    vector<vector<int>> dp(r, vector<int>(c, 0));
    
    dp[0][0] = M[0][0];
    
    for(int i = 1; i < r; i++)
        dp[i][0] = dp[i-1][0] + M[i][0];
        
    for(int j = 1; j < c; j++)
        dp[0][j] = dp[0][j-1] + M[0][j];
        
    for(int i = 1; i < r; i++) {
        for(int j = 1; j < c; j++) {
            dp[i][j] = M[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    
    vector<int> res;
    for(int q = 0; q < Q; q++) {
        int i = q_i[q];
        int j = q_i[q];
        
        int min_dist = min(min(i, j), min(r-i-1, c-j-1));
        int l = 0, r = min_dist;
        int ans = -1;
        
        while(l <= r) {
            int mid = (l + r) / 2;
            int x1 = i - mid, x2 = i + mid;
            int y1 = j - mid, y2 = j + mid;
            
            // Count total no. of 1s in the sub square considered.
            int count = dp[x2][y2];
            if(x1 > 0)
                count -= dp[x1-1][y2];
            if(y1 > 0)
                count -= dp[x2][y1-1];
            if(x1 > 0 && y1 > 0)
                count += dp[x1-1][y1-1];
                
            if(count <= k) {
                ans = 2 * mid + 1;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        if(ans == -1) ans = 0;
        res.push_back(ans);
    }
    
    return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}