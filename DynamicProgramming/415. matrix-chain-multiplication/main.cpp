#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int> &p, int n) { // suppose [1, 2, 3, 4]
	vector<vector<int>> dp(n, vector<int>(n));

	// l = current chain length, i,j = current chain pointers, 
	// k = traversing through the current chain, q = cost of multiplying from p[i] to p[j]
	int i, j, l, k, q;

	// multiplying with itself.
	for(i = 1; i < n; i++)
		dp[i][i] = 0;

	for(l = 2; l < n; l++) {
		for(i = 1; i < n - (l-1); i++) {
			// i -> first matrix of current chain, j -> last matrix of current chain.
			j = i + (l-1);
			dp[i][j] = INT_MAX;

			// multiplying from i to j with different placement of brackets.
			for(k = i; k <= j-1; k++) {
				q = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];

				if(q < dp[i][j])
					dp[i][j] = q;
			}
		}
	}

	return dp[1][n-1];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n; cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++)
	    cin >> p[i];

	cout << matrixChainMultiplication(p, n) << endl;

	return 0;
}