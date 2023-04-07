#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
	int n = nums.size();
	int start = 0, end = n-1;

	if(nums[start] <= nums[end]) // full array is sorted.
		return nums[start];

	while(start <= end) {
		int mid = (start + end) / 2;

		if(mid > 0 && nums[mid] < nums[mid-1])
			return nums[mid];
		if(mid+1 < n && nums[mid+1] < nums[mid])
			return nums[mid+1];

		if(nums[start] <= nums[mid]) // first half is sorted, that means min is present in second half.
			start = mid+1;
		else // second half is sorted, that means min is present in first half.
			end = mid-1;
	}

	return -1;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}