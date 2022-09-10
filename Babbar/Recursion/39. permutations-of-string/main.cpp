#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans, int index) {
	// base case.
	if(index >= nums.size()) {
		ans.push_back(nums);
		return;
	}

	for(int j = index; j < nums.size(); j++) {
		swap(nums[index], nums[j]);
		solve(nums, ans, index+1);

		// backtracking
		swap(nums[index], nums[j]);
	}
}

vector<vector<int>> permute(vector<int> &nums) {
	vector<vector<int>> ans;
	int index = 0;
	solve(nums, ans, index);
	return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}