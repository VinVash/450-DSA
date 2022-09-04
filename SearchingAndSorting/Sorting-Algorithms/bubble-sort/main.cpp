#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n) {
	int i, j;
	bool swapped = false;

	for(i = 0; i < n-1; i++) {
		swapped = false;
		for(j = i; j < n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}

		if(!swapped)
			break;
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

	bubbleSort(nums, n);

	for(auto i: nums)
		cout << i << " ";
	cout << endl;

	return 0;
}