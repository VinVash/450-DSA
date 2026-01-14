#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
	int n = nums.size();

	int i,j; // these two indices need to be swapped.

	for(i = n-2; i >= 0; i--) {
		if(nums[i] < nums[i+1])
			break;
	}
	// i contains its value till now.

	if(i < 0)
		reverse(nums.begin(), nums.end());
	else {
		for(j = n-1; j > i; j--) {
			if(nums[j] > nums[i])
				break;
		}
	
		swap(nums[i], nums[j]);
		reverse(nums.begin(), nums.end());
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}