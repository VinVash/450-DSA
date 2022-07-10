#include <bits/stdc++.h>
using namespace std;

int binaryMedian(vector<vector<int>> &matrix, int r, int c) {
	int min = INT_MAX, max = INT_MIN;

	for(int i = 0; i < r; i++) {
		if(matrix[i][0] < min)
			min = matrix[i][0];

		if(matrix[i][c-1] > max)
			max = matrix[i][c-1];
	}

	// till here min and max are counted.

	int desired = (r * c + 1) / 2;

	while(min < max) {
		// calculate mid
		int mid = (min + max) / 2;
		// initialise place to 0.
		int current = 0;

		// Find count of elements smaller than or equal to mid by for loop.
		for(int i = 0; i < r; i++)
			current += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

		// If current count is less then desired, then median is present in second half.
		if(current < desired)
			min = mid + 1;
		// else it is present in first half.
		else
			max = mid;
	}

	return min;
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

    cout << binaryMedian(matrix, r, c) << endl;


	return 0;
}