#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size) {
	// base case.
	if(size == 0 || size == 1)
		return true;
	
	if(arr[0] > arr[1])
		return false;
	else {
		bool remainingPart = isSorted(arr+1, size-1);
		return remainingPart;
	}
}

int sum(int arr[], int size) {
	if(size == 1)
		return arr[0];

	return arr[0] + sum(arr+1, size-1);
}

bool linearSearch(int arr[], int size, int x) {
	if(arr[0] == x)
		return true;
	else if(size == 1)
		return false;

	return linearSearch(arr+1, size-1, x);
}

bool binarySearch(int arr[], int l, int r, int x) {
	// base case.
	if(l > r)
		return false;
	else {
		int mid = (l + r) / 2;

		if(arr[mid] == x)
			return mid;
		else if(arr[mid] > x) {
			return binarySearch(arr, l, mid-1, x);
		} else {
			return binarySearch(arr, mid+1, r, x);
		}
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	int arr[n];

	for(int i = 0; i < n; i++)
	    cin >> arr[i];

	cout << boolalpha;
	cout << isSorted(arr, n) << endl;

	cout << sum(arr, n) << endl;

	cout << linearSearch(arr, n, 7) << endl;

	cout << binarySearch(arr, 0, n-1, 4) << endl;

	return 0;
}