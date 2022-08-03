#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int> &wt, vector<int> &val, int n) {
	int i, w;

	// rows are the different weights given and cols are the weights which are possible.
	vector<vector<int>> dp(n+1, vector<int>(W+1));

	for(i = 0; i <= n; i++) { // row traversal
		for(w = 0; w <= W; w++) { // col traversal
			if(i == 0 || w == 0)
				dp[i][w] = 0;
			else if(wt[i-1] <= w)
				// since we are using indices, therefore using wt[i-1] and val[i-1]
				dp[i][w] = max(dp[i-1][w], dp[i-1][w - wt[i-1]] + val[i-1]); 
			else
				dp[i][w] = dp[i-1][w]; // copy the elements from the above row into this row.
		}
	}
	return dp[n][W];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}