#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums) {
	int n = nums.size();

	// initialise an array with all elements 1.
	vector<int> LIS(n, 1);

	for(int i = n-1; i >= 0; i--) {
		for(int j = i+1; j < n; j++) {
			if(nums[i] < nums[j])
				LIS[i] = max(LIS[i], 1 + LIS[j]); // adding on to the LIS from j onwards.
		}
	}

	return *max_element(LIS.begin(), LIS.end());
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

	cout << lengthOfLIS(nums) << endl;

	return 0;
}