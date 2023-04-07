#include <bits/stdc++.h>
using namespace std;

int solve(int i, string s, set<string>& wordDict) {
    if(i == s.size())
        return 1;

    string temp;
    for(int j = i; j < s.size(); j++) {
        temp += s[j];
        if(wordDict.find(temp) != wordDict.end()) {
            if(solve(j+1, s, wordDict))
                return 1;
        }
    }

    return 0;
}

int solveMem(int i, string s, set<string>& wordDict, vector<int>& dp) {
    if(i == s.size())
        return 1;

    if(dp[i] != -1)
        return dp[i];

    string temp;
    for(int j = i; j < s.size(); j++) {
        temp += s[j];
        if(wordDict.find(temp) != wordDict.end()) {
            if(solveMem(j+1, s, wordDict, dp))
                return dp[i] = 1;
        }
    }

    return dp[i] = 0;
}

bool wordBreak(string s, vector<string>& wordDict) {

    set<string> st;
    for(auto word: wordDict)
        st.insert(word);

    // return solve(0, s, st);

    vector<int> dp(s.size()+1, -1);
    return solveMem(0, s, st, dp);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}