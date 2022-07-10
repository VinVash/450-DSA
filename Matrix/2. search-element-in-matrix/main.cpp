#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
	int r = matrix.size();
	int c = matrix[0].size();

	if(r == 0) return false; // since there is no element in the matrix.

	int r1 = 0, r2 = r-1;
	int mid;
	while(r1 < r2) {
		mid = (r1 +r2)/2;

		// jump to the next row if the last element of the row is smaller than the target.
		if(matrix[mid][c-1] < target)
			r1 = mid+1;

		// jump to the previous row if the first element of the row is greater than the target.
		else if(matrix[mid][0] > target)
			r2 = mid-1;

		else {
			r1 = mid;
			break;
		}
	}

	// till now, r1 contains the row which might have the target.

	int c1 = 0, c2 = c-1;
	// mid is already defined.

	while(c1 < c2) {
		mid = (c1 + c2)/2;

		// shorten the search space to the second half if mid is less than the target.
		if(matrix[r1][mid] < target)
			c1 = mid+1;

		else if(matrix[r1][mid] > target)
			c2 = mid-1;

		else // the element has been found.
			return true;
	}
	// if nothing has been returned till now, then the element is not present.
	return false;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int r, c, target;
    cin >> r >> c >> target;

   	vector<vector<int>> matrix(r, vector<int>(c, 0));

   	for(int i = 0; i < r; i++) {
   		for(int j = 0; j < c; j++) {
   			cin >> matrix[i][j];
   		}
   	}

   	if(searchMatrix(matrix, target))
   		cout << "Yes" << endl;
   	else
   		cout << "No" << endl;

	return 0;
}