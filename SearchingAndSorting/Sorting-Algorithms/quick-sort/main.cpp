#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
	int pivot = arr[high];
	int i = low-1;

	for(int j = low; j <= high-1; j++) {
		if(arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i+1], arr[high]);
	return i+1;
}

void quickSort(vector<int> &arr, int low, int high) {
	if(low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
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

	quickSort(nums, 0, n-1);

	for(auto i: nums)
		cout << i << " ";
	cout << endl;

	return 0;
}