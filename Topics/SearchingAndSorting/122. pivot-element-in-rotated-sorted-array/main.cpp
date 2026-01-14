#include <bits/stdc++.h>
using namespace std;

int getPivotElement(vector<int> &arr, int l, int r) {
	if(l > r)
		return -1; // array is not rotated.

	if(l == r) return l;

	int m = (l + r) / 2;

	if(m < r && arr[m] > arr[m+1])
		return m;
	if(m > l && arr[m] < arr[m-1])
		return m-1;
	
	if(arr[l] >= arr[m]) // the first half is not sorted, hence the pivot is present in the first half.
		return getPivotElement(arr, l, m-1);
	else // the pivot is present in the second half.
		return getPivotElement(arr, m+1, r);
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

	cout << "Pivot present at index: " <<  getPivotElement(nums, 0, n-1) << endl;

	return 0;
}