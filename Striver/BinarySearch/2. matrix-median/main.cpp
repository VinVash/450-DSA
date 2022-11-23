#include <bits/stdc++.h>
using namespace std;

int countSmallerThanMid(vector<int> &row, int mid) {
	int l = 0, h = row.size() - 1;
	while(l < h) {
		int md = (l + h) / 2;
		if(row[mid] <= mid)
			l = md + 1;
		else
			h = md - 1;
	}

	return l;
}

int findMedian(vector<vector<int>> &matrix) {
	int low = 1;
	int high = 1e9;
	int n = matrix.size();
	int m = matrix[0].size();

	while(low <= high) {
		int mid = (low + high) / 2;
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			cnt += countSmallerThanMid(matrix[i], mid);
		}

		if(cnt <= (n * m) / 2) // the count of numbers below that number should be more than (n * m) / 2,
			// where n * m is the total no. of elements in the 2D matrix.
			low = mid + 1;
		else
			high = mid - 1;
	}

	return low;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}