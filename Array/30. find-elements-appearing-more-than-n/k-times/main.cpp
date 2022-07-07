#include <bits/stdc++.h>
using namespace std;

int moreThanNbyK(vector<int> &nums, int n, int k) {
	int limit = n/k;
	unordered_map<int, int> hmap;
	int res = 0;

	for(int i = 0; i < n; i++) {
		if(hmap[nums[i]]) hmap[nums[i]]++;
		else hmap[nums[i]] = 1;
	}

	for(auto x: hmap)
		if (x.second > limit) res++;

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> nums {1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1};

	cout << moreThanNbyK(nums, nums.size(), 4) << endl;

	return 0;
}