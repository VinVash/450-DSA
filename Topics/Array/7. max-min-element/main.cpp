#include <bits/stdc++.h>
using namespace std;

// No. of comparisons:
// Worst case: 1 + 2(n-2)
// Best case: 1 + n-2
pair<int, int> simpleLinear(vector<int> &nums) {
	pair res = make_pair(0, 0);

	if(nums.size() == 1) {
		res.first = nums[0];
		res.second = nums[0];
		return res;
	}

	if(nums[0] > nums[1]) {
		res.first = nums[1];
		res.second = nums[0];
	} else {
		res.first = nums[0];
		res.second = nums[1];
	}

	for(int i = 2; i < nums.size(); i++) {
		if (nums[i] > res.second)
			res.second = nums[i];
		else if (nums[i] < res.first)
			res.first = nums[i];
	}
	return res;
}

// Tournament method
// Divide the array into two parts and compare the maximums and 
// minimums of the two parts to get the maximum and the minimum
// of the whole array.
// There are 3n/2 - 2 comparisons in this method.
pair<int, int> tournament(vector<int> &nums, int l, int r) {
	pair res = make_pair(0, 0);

	if(l == r) {
		res.first = nums[l];
		res.second = nums[l];
		return res;
	}

	if(r == l+1) {
		if(nums[l] < nums[r]) {
			res.first = nums[l];
			res.second = nums[r];
		} else {
			res.first = nums[r];
			res.second = nums[l];
		}
		return res;
	}

	int mid = (l + r) / 2;
	pair resl = tournament(nums, l, mid); // result of the left part.
	pair resr = tournament(nums, mid+1, r); // result of the right part.

	if(resl.first < resr.first)
		res.first = resl.first;
	else
		res.first = resr.first;

	if(resl.second > resr.second)
		res.second = resl.second;
	else
		res.second = resr.second;

	return res;
}

// Compare in pairs
// Choose the initial pair(res) acording to the first two elements if n is even,
// and according to the first element if n is odd. This way, the rest array
// can be divided into pairs, which need to be compared to the initial pair.
// Then return the res pair.
// No. of comparisons: 3n/2 - 2
pair<int, int> compareInPairs(vector<int> &nums) {
	int n = nums.size();

	pair res = make_pair(0, 0);
	int i = 0;

	if(n % 2 == 0) {
		if(nums[0] < nums[1]) {
			res.first = nums[0];
			res.second = nums[1];
		} else {
			res.first = nums[1];
			res.second = nums[0];
		}
		i = 2; // starting index for while loop.

	} else {
		res.first = nums[0];
		res.second = nums[0];
		i = 1; // starting index for while loop.
	}

	while(i < n-1) { // takes care of i+1 being in range
		if(nums[i] > nums[i+1]) {
			if(nums[i] > res.second)
				res.second = nums[i];
			if(nums[i+1] < res.first)
				res.first = nums[i+1];
		} else {
			if(nums[i+1] > res.second)
				res.second = nums[i+1];
			if(nums[i] < res.first)
				res.first = nums[i];
		}

		i+=2;
	}

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    vector<int> nums = { 100, 11, 445, 1, 330, 3000 };
    // pair res = simpleLinear(nums);
    // pair res = tournament(nums, 0, nums.size()-1);
    pair res = compareInPairs(nums);

    cout << "Max is: " << res.second << endl;
    cout << "Min is: " << res.first << endl;

	return 0;
}