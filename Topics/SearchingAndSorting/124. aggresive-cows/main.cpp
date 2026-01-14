#include <bits/stdc++.h>
using namespace std;

bool isPossible(int dist, vector<int> &stalls, int n, int c) {
	int prevPos = stalls[0]; // place the first cow at the first stall.
	int cowsPlaced = 1;

	for(int i = 1; i < n; i++) {
		if(stalls[i] - prevPos >= dist) {
			prevPos = stalls[i];
			cowsPlaced++;
		}

		if(cowsPlaced == c)
			return true;
	}

	return false; // if not possible to place the cows with minimum distance.
}

// Time : O(n*logn).
int solve(vector<int> &stalls, int n, int c) {
	sort(stalls.begin(), stalls.end());

	int high = stalls[n-1] - stalls[0], low = 1; // minDistance will lie between low and high.
	int minDistance = low; // initialise minDistance to low.

	while(low <= high) {
		int mid = (low + high) / 2;
		if(isPossible(mid, stalls, n, c)) {
			minDistance = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return minDistance;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;

	while(t) {
		int n, c;
		cin >> n >> c;
		vector<int> stalls(n);

		for(int i = 0; i < n; i++)
		    cin >> stalls[i];

		cout << solve(stalls, n, c) << endl;

		t--;
	}


	return 0;
}