#include <bits/stdc++.h>
using namespace std;

void moveNegative(vector<int> &nums) {
	int l = 0, r = nums.size()-1;

	while(l < r) {
		if(nums[l] < 0)
			l++;
		else if (nums[r] > 0)
			r--;
		else
			swap(nums[l], nums[r]);
	}
}

void moveNegative2(vector<int> &nums) {
	int l = 0, r = nums.size()-1;

	while(l <= r) {
		if(nums[l] < 0 && nums[r] > 0) {
			l++; r--;
		} else if(nums[l] > 0 && nums[r] < 0) {
			swap(nums[l], nums[r]);
			l++; r--;
		} else if(nums[l] > 0 && nums[r] > 0) {
			r--; // only move the right pointer, let the left pointer remain as it is.
		} else {
			l++; // only move the left pointer, let the right pointer remain as it is.
		}
	}
}

void moveNegative3(vector<int> &nums) {
	int j = 0; // negative pointer

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] < 0) {
			swap(nums[i], nums[j]);
			j++;
		}
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> nums {1, -1, 1, -2, 3, -4, -5, 7, 3};

	// moveNegative(nums);
	// moveNegative2(nums);
	moveNegative3(nums);

	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;

	return 0;
}