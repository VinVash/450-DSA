#include <bits/stdc++.h>
using namespace std;

int solveRec(string a, string b, int i, int j) {
	// base case.
	if(i == a.size()) {
		return b.size() - j;
	}

	if(j == b.size()) {
		return a.size() - i;
	}

	int ans = 0;
	if(a[i] == b[j]) {
		return solveRec(a, b, i+1, j+1);
	} else {
		// insert
		int insertAns = 1 + solveRec(a, b, i, j+1);

		// delete
		int deleteAns = 1 + solveRec(a, b, i+1, j);

		// replace
		int replaceAns = 1 + solveRec(a, b, i+1, j+1);

		ans = min(insertAns, min(deleteAns, replaceAns));
	}

	return ans;
}

int solveMem(string a, string b, int i, int j, vector<vector<int>> &dp) {
    // base case.
    if(i == a.size()) {
        return b.size() - j;
    }

    if(j == b.size()) {
        return a.size() - i;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if(a[i] == b[j]) {
        return solveMem(a, b, i+1, j+1, dp);
    } else {
        // insert
        int insertAns = 1 + solveMem(a, b, i, j+1, dp);

        // delete
        int deleteAns = 1 + solveMem(a, b, i+1, j, dp);

        // replace
        int replaceAns = 1 + solveMem(a, b, i+1, j+1, dp);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }

    dp[i][j] = ans;
    return dp[i][j];
}

int solveTab(string a, string b) {
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
    
    for(int j = 0; j < b.size(); j++) {
        dp[a.size()][j] = b.size() - j;
    }
    
    for(int i = 0; i < a.size(); i++) {
        dp[i][b.size()] = a.size() - i;
    }
    
    for(int i = a.size()-1; i >= 0; i--) {
        for(int j = b.size()-1; j >= 0; j--) {
            int ans = 0;
            if(a[i] == b[j]) {
                ans = dp[i+1][j+1];
            } else {
                // insert
                int insertAns = 1 + dp[i][j+1];

                // delete
                int deleteAns = 1 + dp[i+1][j];;

                // replace
                int replaceAns = 1 + dp[i+1][j+1];;

                ans = min(insertAns, min(deleteAns, replaceAns));
            }

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string word1, word2;
	cin >> word1 >> word2;

    vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
    cout << solveMem(word1, word2, 0, 0, dp);

	return 0;
}