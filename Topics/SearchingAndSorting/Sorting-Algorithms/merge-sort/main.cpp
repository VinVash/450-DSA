#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r) {
	int len1 = m - l + 1;
	int len2 = r - m;

	vector<int> leftArr(len1+1);
	vector<int> rightArr(len2+1);

	for(int i = 0; i < len1; i++) {
		leftArr[i] = arr[l+i];
	}

	for(int j = 0; j < len2; j++) {
		rightArr[j] = arr[m+1+j];
	}

	int i, j, k;
	i = 0, j = 0, k = l;

	while(i < len1 && j < len2) {
		if(leftArr[i] < rightArr[j]) {
			arr[k] = leftArr[i];
			i++;
		} else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}

	while(i < len1) {
		arr[k] = leftArr[i];
		k++; i++;
	}

	while(j < len2) {
		arr[k] = rightArr[j];
		k++; j++;
	}
}

void mergeSort(vector<int> &arr, int l, int r) {
	if(l < r) {
		int m = (l+r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
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

	mergeSort(nums, 0, n-1);

	for(auto i: nums)
		cout << i << " ";
	cout << endl;

	return 0;
}