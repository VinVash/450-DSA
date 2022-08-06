#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<vector<int>> &matrix, int i, int j, int &maxi) {
	// base case.
	if(i >= matrix.size() || j >= matrix[0].size())
		return 0;

	int right = solveRec(matrix, i, j+1, maxi);
	int diagonal = solveRec(matrix, i+1, j+1, maxi);
	int down = solveRec(matrix, i+1, j, maxi);

	if(matrix[i][j] == 1) {
		int ans = 1 + min(right, min(diagonal, down));
		maxi = max(maxi, ans);
		return ans;
	} else {
		return 0;
	}
}

int solveMem(vector<vector<int>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp) {
	// base case.
	if(i >= matrix.size() || j >= matrix[0].size())
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	int right = solveMem(matrix, i, j+1, maxi, dp);
	int diagonal = solveMem(matrix, i+1, j+1, maxi, dp);
	int down = solveMem(matrix, i+1, j, maxi, dp);

	if(matrix[i][j] == 1) {
		dp[i][j] = 1 + min(right, min(diagonal, down));
		maxi = max(maxi, dp[i][j]);
		return dp[i][j];
	} else {
		return dp[i][j] = 0;
	}
}

int solveTab(vector<vector<int>> &matrix, int &maxi) {
	int row = matrix.size();
	int col = matrix[0].size();

	vector<vector<int>> dp(row+1, vector<int>(col+1, 0));

	for(int i = row-1; i >= 0; i--) {
		for(int j = col-1; j >= 0; j--) {
			int right = dp[i][j+1];
			int diagonal = dp[i+1][j+1];
			int down = dp[i+1][j];

			if(matrix[i][j] == 1) {
				dp[i][j] = 1 + min(right, min(diagonal, down));
				maxi = max(maxi, dp[i][j]);
			} else {
				dp[i][j] = 0;
			}
		}
	}

	return dp[0][0];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	// int maxi = 0;
	// solveRec(matrix, 0, 0, maxi);
	// return maxi;

 //    int maxi = 0;
	// vector<vector<int>> dp(n, vector<int>(m, -1));
	// cout << solveMem(matrix, 0, 0, maxi, dp);
	// return maxi;

	int maxi = 0;
	cout << solveTab(matrix, maxi) << endl;

	return 0;
}