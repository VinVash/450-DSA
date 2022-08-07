#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &dp, int i, int j, string s) {
	// base cases.
	dp[i][j] = 0;

	// step 3.
	if(dp[i][j] != -1)
		return dp[i][j];

	if(i == j)
		return dp[i][j] = 1;

	if(j - i == 1) {
		if(s[i] == s[j])
			return dp[i][j] = 1;
		else
			return dp[i][j]; // contains 0.
	}

	if(s[i] == s[j] && solve(dp, i+1, j-1, s) == 1)
		return dp[i][j] = 1;

	return dp[i][j];
}

string longestPalindromicSubstring(string s) {
	int n = s.size();
	int start_index = 0, max_len = 0;

	// initialise 2d matrix(nxn) with all elements -1.
	vector<vector<int>> dp(n, vector<int>(n, -1));

	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			solve(dp, i, j, s);
			if(dp[i][j] == 1) {
				if(j-i+1 > max_len) {
					max_len = max(max_len, j-i+1);
					start_index = i;
				}
			}
		}
	}
	return s.substr(start_index, max_len);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}