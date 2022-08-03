#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string t) {
    int m = s.size();
    int n = t.size();
    
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
        }
    }
    
    return dp[m][n];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s, t;
	cin >> s >> t;

	cout << editDistance(s, t) << endl;

	return 0;
}