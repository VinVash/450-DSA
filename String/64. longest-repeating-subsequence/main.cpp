#include <bits/stdc++.h>
using namespace std;

int longestRepeating(string s) {
	int n = s.size();

	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

	for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            // If characters match and indexes are
            // not same
            if (s[i-1] == s[j-1] && i != j)
                dp[i][j] =  1 + dp[i-1][j-1];         
                      
            // If characters do not match
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

	return dp[n][n];
}

// Recursive solution.
int lrs(string s, int i, int j, vector<vector<int>> &dp) {
	
	// Out of bounds.
	if(i >= s.size() || j >= s.size())
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	if(dp[i][j] == -1) {
		if(s[i] == s[j] && i != j)
			dp[i][j] = 1 + lrs(s, i+1, j+1, dp);
		else
			dp[i][j] = max(lrs(s, i+1, j, dp), lrs(s, i, j+1, dp));
	}

	return dp[i][j];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s;
	cin >> s;

	cout << longestRepeating(s) << endl;

	vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
	cout << lrs(s, 0, 0, dp) << endl;


	return 0;
}