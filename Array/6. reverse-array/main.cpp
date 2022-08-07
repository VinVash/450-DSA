#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
void reverseArray(vector<int> &nums, int start, int end) {
	while(start < end) {
		int temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++;
		end--;
	}
}

// Time complexity: O(n)
void recursiveReverse(vector<int> &nums, int start, int end) {
	if(start >= end) return;

	int temp = nums[start];
	nums[start] = nums[end];
	nums[end] = temp;

	recursiveReverse(nums, start+1, end-1);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    vector<int> nums = {1, 2, 3, 4, 5, 6};
    // reverseArray(nums, 0, nums.size()-1);
    recursiveReverse(nums, 0, nums.size()-1);

    for(auto x: nums)
    	cout << x << " ";
    cout << endl;

	return 0;
}