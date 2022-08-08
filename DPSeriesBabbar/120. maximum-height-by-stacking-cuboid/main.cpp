#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &base, vector<int> &newBox) {
	if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
		return true;
	return false;
}

int solveTabSO(int n, vector<vector<int>> &a) {
	vector<int> currRow(n+1, 0);
	vector<int> nextRow(n+1, 0);

	for(int curr=n-1; curr >= 0; curr--) {
		for(int prev=curr-1; prev >= -1; prev--) {
			// include
			int inc = 0;
			if(prev == -1 || check(a[curr], a[prev]));
				inc = a[curr][2] + nextRow[curr+1]; // adding the height of current row cuboid.

			// exclude
			int exc = 0 + nextRow[prev+1];

			currRow[prev+1] = max(inc, exc);
		}
		nextRow = currRow;
	}
	return nextRow[0];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<vector<int>> cuboids;

	// step 1: sort all dimensions for every cuboid.
	for(auto &a: cuboids) {
		sort(a.begin(), a.end());
	}

	// step 2: sort all cuboids basis on w or l
	sort(cuboids.begin(), cuboids.end());

	// step 3: use LIS logic
	return solveTabSO(cuboids.size(), cuboids);

	return 0;
}