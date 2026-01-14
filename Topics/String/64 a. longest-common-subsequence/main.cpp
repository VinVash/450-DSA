#include <bits/stdc++.h>
using namespace std;

int longestCommon(string s1, string s2) {
	int n1 = s1.size();
	int n2 = s2.size();

	vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

	for(int i = 0; i <= n1; i++) {
		for(int j = 0; j <= n2; j++) {
			if(i == 0 || j == 0)
				dp[i][j] = 0;

			else if(s1[i-1] == s2[j-1]) // i-1 and j-1 are used for comparing because loop is running from 0 to n1(equal) and 0 to n2(equal).
				dp[i][j] = 1 + dp[i-1][j-1];

			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}

	return dp[n1][n2];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s1, s2;
	cin >> s1 >> s2;

	cout << longestCommon(s1, s2) << endl;


	return 0;
}