#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && arr[l] > arr[largest])
		largest = l;
	if(r < n && arr[r] > arr[largest])
		largest = r;
	
	// Till now we have found the largest.

	if(largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(vector<int> &arr, int n) {
	for(int i = n/2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	for(int i = n-1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
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

	heapSort(nums, n);

	for(auto i: nums)
		cout << i << " ";
	cout << endl;

	return 0;
}