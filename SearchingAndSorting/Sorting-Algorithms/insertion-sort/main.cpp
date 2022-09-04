#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n) {
	int i, j, key;

	for(int i = 1; i < n; i++) {
		key = arr[i];
		j = i-1;

		while(j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j = j-1;
		}

		arr[j+1] = key;
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++)
	    cin >> nums[i];

	insertionSort(nums, n);

	for(auto i: nums)
		cout << i << " ";
	cout << endl;

	return 0;
}