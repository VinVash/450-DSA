#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubsequences(string s) {
	int n = s.size();

	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

	for(int i = 0; i < n; i++)
		dp[i][i] = 1; // palindromic subsequence of length 1.

	// check subsequence of length l is palindrome or not.
	for(int l = 2; l <= n; l++) {
		for(int i = 0; i <= n-l; i++) {
			int j = l + i - 1;
			if(s[i] == s[j])
				dp[i][j] = 1 + dp[i][j-1] + dp[i+1][j];
			else
				dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
		}
	}

	return dp[0][n-1];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s; cin >> s;

	cout << countPalindromicSubsequences(s) << endl;

	return 0;
}