#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findSubarrays(vector<int> &arr) {
	int n = arr.size();

	unordered_map<int, vector<int>> hmap;

	vector<pair<int, int>> out; // to store the starting and ending index of subarray.

	int sum = 0;

	for(int i = 0; i < n; i++) {
		sum += arr[i];

		if(sum == 0)
			out.push_back(make_pair(0, i)); // subarray from index 0 to i has sum 0.

		if(hmap.find(sum) != hmap.end()) {
			// map[sum] stores starting index of all subarrays.
			vector<int> vc = hmap[sum];
			for(auto it = vc.begin(); it != vc.end(); it++)
				out.push_back(make_pair(*it + 1, i));
		}

		hmap[sum].push_back(i);
	}

	return out;
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

	vector<pair<int, int>> res = findSubarrays(nums);

	if(res.size()) {
		for(auto it: res) {
			cout << it.first << " " << it.second << endl;
		}
	} else {
		cout << "No" << endl;
	}

	return 0;
}