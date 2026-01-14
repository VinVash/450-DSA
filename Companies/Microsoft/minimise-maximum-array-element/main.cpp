#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int n, int mid, int k) {
	int count = 0;

	for(int i = 0; i < n; i++) {
		count += (arr[i] - 1) / mid;
	}

	return count <= k;
}

// O(n * logm(m))   m -> maximum element of the array.
int minimiseMax(vector<int> &arr, int n, int k) {
	int l = 1, r = *max_element(arr.begin(), arr.end());

	int mid;

	while(l < r) {
		mid = (l + r) / 2;

		if(isPossible(arr, n, mid, k))
			r = mid;
		else
			l = mid + 1;
	}

	return r; // max element.
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}