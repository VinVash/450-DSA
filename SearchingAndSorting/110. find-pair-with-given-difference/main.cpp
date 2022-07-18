#include <bits/stdc++.h>
using namespace std;

bool findPair(vector<int> &arr, int size, int n) {
	sort(arr.begin(), arr.end());

	int l = 0, r = 1;

	while(l <= r && r < size) {
		int diff = arr[r] - arr[l];
		if(diff == n && l != r) // since we need distince elements in the pair.
			return true;
		else if(diff > n) // try to reduce the difference.
			l++;
		else
			r++; // increase the difference.
	}

	return false;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int size; cin >> size;
    vector<int> nums(size);

    for(int i = 0; i < size; i++)
        cin >> nums[i];

    int n; cin >> n;

    if(findPair(nums, size, n))
    	cout << "Found" << endl;
    else
    	cout << "Not Found" << endl;

	return 0;
}