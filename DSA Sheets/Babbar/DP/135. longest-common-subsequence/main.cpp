#include <bits/stdc++.h>
using namespace std;

int solveRec(string a, string b, int i, int j, vector<vector<int>> &dp) {
	// base case.
	if(i == a.size())
		return 0;
	if(j == b.size())
		return 0;

	 if(dp[i][j] != -1)
	 	return dp[i][j];

	int ans = 0;
	if(a[i] == b[j]) {
		ans = 1 + solveRec(a, b, i+1, j+1, dp);
	} else {
		ans = max(solveRec(a, b, i+1, j, dp), solveRec(a, b, i, j+1, dp));
	}

	return dp[i][j] = ans;
}

int solveTab(string a, string b) {
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	vector<int> curr(m, 0);
	vector<int> next(m, 0);

	for(int i = n-1; i >= 0; i--) {
		for(int j = m-1; j >= 0; j--) {
			int ans = 0;
			if(a[i] == b[j]) {
				ans = 1 + next[j+1];
			} else {
				ans = max(next[j], curr[j+1]);
			}

			curr[j] = ans;
		}
		next = curr;
	}

	return next[0];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s1 = "abcd", s2 = "bcde";

	cout << solveTab(s1, s2) << endl;

	return 0;
}