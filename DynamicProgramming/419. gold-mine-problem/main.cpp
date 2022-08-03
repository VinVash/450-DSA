#include <bits/stdc++.h>
using namespace std;

// Exponential solution, O(3^(n*m))
int collectGold(vector<vector<int>> &gold, int x, int y, int n, int m) {
	// Base case.
	if((x < 0) || (x == n) || (y == m))
		return 0;

	int rightUpper = collectGold(gold, x-1, y+1, n, m);
	int right = collectGold(gold, x, y+1, n, m);
	int rightLower = collectGold(gold, x+1, y+1, n, m);

	return gold[x][y] + max(rightUpper, max(right, rightLower));
}

// DP solution, O(m*n)  // Also, here we have taken mXn matrix.
int getMaxGold(vector<vector<int>> &gold, int m, int n) {
	vector<vector<int>> goldTable(m, vector<int>(n, 0));

	for(int col = n-1; col >= 0; col--) {
		for(int row = 0; row < m; row++) {
			int right = (col == n-1) ? 0 : goldTable[row][col+1];

			int rightUpper = (row == 0 || col == n-1) ? 0 : goldTable[row-1][col+1];

			int rightLower = (row == m-1 || col == n-1) ? 0 : goldTable[row+1][col+1];

			goldTable[row][col] = gold[row][col] + max(right, max(rightUpper, rightLower));
		}
	}

	int res = goldTable[0][0];
	for(int i = 1; i < m; i++)
		res = max(res, goldTable[i][0]);

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}