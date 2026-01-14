#include <bits/stdc++.h>
using namespace std;

int findMaxValue(vector<vector<int>> &m, int r, int c) {
	
	// Initialise maxArray with same dimensions.
	vector<vector<int>> maxArray(r, vector<int>(c, 0));

	// Build up last row.
	int maxVal = m[r-1][c-1];
	for(int j = c-2; j >= 0; j--) {
		if(m[r-1][j] > maxVal)
			maxVal = m[r-1][j];
		maxArray[r-1][j] = maxVal;
	}

	// Build up last col.
	maxVal = m[r-1][c-1];
	for(int i = r-2; i >= 0; i--) {
		if(m[i][c-1] > maxVal)
			maxVal = m[i][c-1];
		maxArray[i][c-1] = maxVal;
	}

	// Build up remaining matrix.
	for(int i = r-2; i >= 0; i--) {
		for(int j = c-2; j >= 0; j--) {
			if(maxArray[i+1][j+1] - m[i][j] > maxVal)
				maxVal = maxArray[i+1][j+1] - m[i][j];
			maxArray[i][j] = max(m[i][j], max(maxArray[i][j+1], maxArray[i+1][j]));
		}
	}

	return maxVal;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int r, c;
	cin >> r >> c;

	vector<vector<int>> matrix(r, vector<int>(c, 0));

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++)
			cin >> matrix[i][j];
	}

	cout << findMaxValue(matrix, r, c) << endl;


	return 0;
}