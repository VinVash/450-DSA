#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict) {
	int n = s.size();

	vector<int> dp(n+1, false);
	dp[n] = true;

	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < wordDict.size(); j++) {
			if(i + wordDict[j].size() <= n && s.substr(i, wordDict[j].size()) == wordDict[j])
				dp[i] = dp[i + wordDict[j].size()];
		}
	}
	return dp[0];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    string s; cin >> s;

    vector<string> wordDict {"i", "like", "sam", "sung", "samsung", "mobile",
							"ice","cream", "icecream", "man", "go", "mango"};

	if(wordBreak(s, wordDict))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;


	return 0;
}