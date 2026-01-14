#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int n) {
	int i, j, min_index;

	for(int i = 0; i < n-1; i++) {
		min_index = i;
		for(int j = i+1; j < n; j++) {
			if(arr[j] < arr[min_index])
				min_index = j;
		}
		swap(arr[min_index], arr[i]);
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

	selectionSort(nums, n);

	for(auto i: nums)
		cout << i << " ";
	cout << endl;

	return 0;
}