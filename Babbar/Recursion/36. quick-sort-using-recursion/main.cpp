#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int l, int r) {
	int pivot = arr[r];
	int i = l-1;

	for(int j = l; j <= r-1; j++) {
		if(arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i+1], arr[r]);
	return i+1;
}

void quickSort(vector<int> &arr, int l, int r) {
	// base case
	if(l >= r)
		return;

	int pi = partition(arr, l, r);
	quickSort(arr, l, pi-1);
	quickSort(arr, pi+1, r);
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

	quickSort(nums, 0, n-1);

	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;

	return 0;
}