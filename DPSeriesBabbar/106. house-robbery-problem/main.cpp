#include <bits/stdc++.h>
using namespace std;

int solveTabSO(vector<int> &nums) {
	int n = nums.size();

	int prev2 = 0;
	int prev1 = nums[0];

	for(int i = 1; i < n; i++) {
		int inc = prev2 + nums[i];
		int exc = prev1 + 0;
		int ans = max(inc, exc);

		prev2 = prev1;
		prev1 = ans;
	}

	return prev1;
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

	vector<int> v; // for passing in the function calls.

	v.assign(nums.begin(), nums.end()-1);
	int res1 = solveTabSO(v);

	v.assign(nums.begin()+1, nums.end());
	int res2 = solveTabSO(v);

	cout << max(res1, res2) << endl;

	return 0;
}