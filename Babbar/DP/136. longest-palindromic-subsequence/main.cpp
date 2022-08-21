#include <bits/stdc++.h>
using namespace std;

int solveTab(string a, string b) {
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	vector<int> curr(m+1, 0);
	vector<int> next(m+1, 0);

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

	string s; cin >> s;
	int n = s.size();
	string s2 = s;
	for(int i = 0; i < n/2; i++) {
		swap(s2[i], s2[n-i-1]);
	}

	cout << solveTab(s, s2) << endl;

	return 0;
}