#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
   	return nums[k-1];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    vector<int> nums {5, 4, 3, 2, 1};
    cout << kthSmallest(nums, 3);

	return 0;
}