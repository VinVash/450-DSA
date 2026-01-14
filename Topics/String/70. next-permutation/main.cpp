#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr, int l, int r) {
	while(l < r) {
		swap(arr[r], arr[l]);
		l++;
		r--;
	}
}

vector<int> nextPermutation(vector<int> &arr, int n) {
	// i stores the first index from back which is lesser than its next element.
	// j stores the index which needs to be swapped with i, i.e.,
	// j is the first element from back which is greater than element at i.
	int i, j;

	for(i = n-2; i >= 0; i--) {
		if(arr[i] < arr[i+1])
			break;
	}

	// till here, i has its final value.

	if(i < 0) {
		// arr was in strictly decreasing order, 
		// therefore change it to strictly increasing order.
		reverse(arr.begin(), arr.end());
	} else {
		for(j = n-1; j > i; j--) {
			if(arr[j] > arr[i])
				break;
		}

		// till here, j contains its final value.
		swap(arr[i], arr[j]);
		reverse(arr.begin() + i + 1, arr.end());
	}

	return arr;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	vector<int> arr(n);

	for(int i = 0; i < n; i++)
	    cin >> arr[i];

	vector<int> res = nextPermutation(arr, n);

	for(int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}