#include <bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int> &arr, int n, int k) {
	sort(arr.begin(), arr.end());

	int res = arr[n-1] - arr[0];
	int tempmax = arr[n-1];
	int tempmin = arr[0];

	for(int i = 1; i < n; i++) {
		if (arr[i]-k < 0) continue;

		tempmin = min(arr[0]+k, arr[i]-k);
		tempmax = max(arr[n-1]-k, arr[i-1]+k);

		res = min(res, tempmax-tempmin);
	}

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> arr {1, 5, 8, 10};

	int k; cin >> k;
	cout << getMinDiff(arr, arr.size(), k) << endl;;


	return 0;
}