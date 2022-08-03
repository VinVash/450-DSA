#include <bits/stdc++.h>
using namespace std;

int countFriendsPairings(int n) {
	vector<int> dp(n+1, 0);

	for(int i = 0; i <= n; i++) {
		if(i <= 2)
			dp[i] = i;
		else
			dp[i] = dp[i-1] + (i-1) * dp[i-2];
	}

	return dp[n];
}

int countFriendsPairings2(vector<int> &dp, int n) {
	if(dp[n] != -1)
		return dp[n];

	if(n > 2)
		return dp[n] = countFriendsPairings2(dp, n-1) + (n-1) * countFriendsPairings2(dp, n-2);
	else
		return dp[n] = n;
}

int countFriendsPairings3(int n) {
	int a = 1, b = 2, c = n;

	if(n <= 2)
		return n;

	for(int i = 3; i <= n; i++) {
		c = b + (i-1) * a;
		a = b;
		b = c;
	}

	return c;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	// For countFriendsPairings2
	int n = 4;
	vector<int> dp(n, -1);

	cout << countFriendsPairings2(dp, n) << endl;

	return 0;
}