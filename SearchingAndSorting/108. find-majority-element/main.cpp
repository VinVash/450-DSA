#include <bits/stdc++.h>
using namespace std;

// failing testcase for Moore's Voting Approach:
// 12
// 1 2 3 3 1 2 4 3 3 3 3 3

int MooresVoting(vector<int> &nums) { // wrong approach.
	int n = nums.size();
	int maj_index = 0, count = 1;

	for(int i = 1; i < n; i++) {
		if(nums[i] == nums[maj_index])
			count++;
		else
			count--;

		if(count == 0) {
			maj_index = i;
			count = 1;
		}
	}

	cout << count << endl;
	return nums[maj_index];
}

// working with time: O(n) space: O(n)
int findCandidate(vector<int> &nums) {
	int n = nums.size();

	unordered_map<int, int> hmap;
	for(int i = 0; i < n; i++)
		hmap[nums[i]]++;

	bool found = false;
	int ans = 0;

	for (auto i: hmap) {
		if(i.second > n / 2) {
			found = true;
			ans = i.first;
			break;
		}
	}

	if(found)
		return ans;

	return -1;
}

int findCandidate2(vector<int> &nums) {
	int n = nums.size();
	sort(nums.begin(), nums.end());

	int count = 1;
	for(int i = 1; i < n; i++) {
		if(nums[i] == nums[i-1])
			count++;
		else {
			if (count > n/2)
				return nums[i-1];

			count = 1;
		}
	}

	return -1;
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

	cout << findCandidate(nums) << endl;
	cout << findCandidate2(nums) << endl;

	return 0;
}
