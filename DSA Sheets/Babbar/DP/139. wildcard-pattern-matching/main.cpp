#include <bits/stdc++.h>
using namespace std;

bool solveRec(string s, string p, int i, int j) {
	// base case.
	if(i < 0 && j < 0) { // valid pattern.
		return true;
	}

	if(i >= 0 && j < 0) { // invalid pattern.
		return false;
	}

	if(i < 0 && j >= 0) {
		for(int k = 0; k <= j; k++) {
			if(p[k] != '*')
				return false;
		}
		return true;
	}

	// match
	if(s[i] == p[j] || p[j] == '?') {
		return solveRec(s, p, i-1, j-1);
	} else if(p[j] == '*') {
		return solveRec(s, p, i-1, j) || solveRec(s, p, i, j-1);
	} else {
		return false;
	}
}

// Time: O(N * M), Space: O(N * M)
bool solveMem(string s, string p, int i, int j, vector<vector<int>> &dp) {
	// base case.
	if(i == 0 && j == 0) { // valid pattern.
		return true;
	}

	if(i > 0 && j == 0) { // invalid pattern.
		return false;
	}

	if(i == 0 && j > 0) {
		for(int k = 1; k <= j; k++) {
			if(p[k-1] != '*')
				return false;
		}
		return true;
	}

	if(dp[i][j] != -1)
		return dp[i][j];

	// match
	if(s[i-1] == p[j-1] || p[j-1] == '?') {
		return dp[i][j] = solveMem(s, p, i-1, j-1, dp);
	} else if(p[j-1] == '*') {
		return dp[i][j] = solveMem(s, p, i-1, j, dp) || solveMem(s, p, i, j-1, dp);
	} else {
		return dp[i][j] = false;
	}
}

// Time: O(N * M), Space: O(M)
bool solveTab(string s, string p) {
	// vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, 0));

	vector<int> prev(p.size()+1, 0);
	vector<int> curr(p.size()+1, 0);

	prev[0] = true;

	for(int j = 1; j <= p.size(); j++) {
		bool flag = true;
		for(int k = 1; k <= j; k++) {
			if(p[k] != '*') {
				flag = false;
				break;
			}
		}
		prev[j] = flag;
	}

	for(int i = 1; i <= s.size(); i++) {
		for(int j = 1; j <= p.size(); j++) {
			if(s[i-1] == p[j-1] || p[j-1] == '?') {
				curr[j] = prev[j-1];
			} else if(p[j-1] == '*') {
				curr[j] = ( prev[j] || curr[j-1] );
			} else {
				curr[j] = false;
			}
		}
		prev = curr;
	}

	return prev[p.size()];
}

bool isMatch(string s, string p) {
	// return solveRec(s, p, s.size()-1, p.size()-1);

	// vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
	// return solveMem(s, p, s.size(), p.size(), dp);

	return solveTab(s, p);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}