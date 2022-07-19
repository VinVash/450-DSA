#include <bits/stdc++.h>
using namespace std;

int kthSmallestOfTwoSortedArrays(vector<int> &arr1, vector<int> &arr2, int n, int m, int k) {
	int i = 0, j = 0, temp = 0;
	bool found = false;
	int res = 0;

	while(i < n && j < m) {
		if(arr1[i] < arr2[j]) {
			temp++;
			if(temp == k) {
				found = true;
				res = arr1[i];
				break;
			}
			i++;
		} else {
			temp++;
			if(temp == k) {
				found = true;
				res = arr2[j];
				break;
			}
			j++;
		}
	}

	if(!found) {
		while(i < n) {
			temp++;
			if(temp == k) {
				found = true;
				res = arr1[i];
				break;
			}
			i++;
		}

		while(j < m) {
			temp++;
			if(temp == k) {
				found = true;
				res = arr2[j];
				break;
			}
			j++;
		}
	}

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;

	vector<int> arr1(n);
	for(int i = 0; i < n; i++)
	    cin >> arr1[i];

	vector<int> arr2(m);
	for(int i = 0; i < m; i++)
	    cin >> arr2[i];

	int k; cin >> k;

	cout << kthSmallestOfTwoSortedArrays(arr1, arr2, n, m, k) << endl;

	return 0;
}