#include <bits/stdc++.h>
using namespace std;

// step 1: insert -1 in the beginning of both the arrays.
// step 2: condition.

int solveRec(vector<int> &nums1, vector<int> &nums2, int index, bool swapped) {
	// base case.
	if(index == nums1.size())
		return 0;
	
	int ans = INT_MAX;

	int prev1 = nums1[index-1];
	int prev2 = nums2[index-1];

	// catch
	if(swapped)
		swap(prev1, prev2);

	// no swap.
	if(nums1[index] > prev1 && nums2[index] > prev2)
		ans = solveRec(nums1, nums2, index+1, 0); // pass 0 since we haven't swapped.

	// swap
	if(nums1[index] > prev2 && nums2[index] > prev1)
		ans = min(ans, 1 + solveRec(nums1, nums2, index+1, 1));

	return ans;
}

int solveMem(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp) {
	// base case.
	if(index == nums1.size())
		return 0;

	if(dp[index][swapped] != -1)
		return dp[index][swapped];
	
	int ans = INT_MAX;

	int prev1 = nums1[index-1];
	int prev2 = nums2[index-1];

	// catch
	if(swapped)
		swap(prev1, prev2);

	// no swap.
	if(nums1[index] > prev1 && nums2[index] > prev2)
		ans = solveMem(nums1, nums2, index+1, 0, dp); // pass 0 since we haven't swapped.

	// swap
	if(nums1[index] > prev2 && nums2[index] > prev1)
		ans = min(ans, 1 + solveMem(nums1, nums2, index+1, 1, dp));

	dp[index][swapped] = ans;
	return dp[index][swapped];
}

int solveTab(vector<int> &nums1, vector<int> &nums2) {
	int n = nums1.size();
	vector<vector<int>> dp(n+1, vector<int>(2, 0));

	for(int index=n-1; index >= 1; index--) {
		for(int swapped=1; swapped >= 0; swapped--) {
			int ans = INT_MAX;

			int prev1 = nums1[index-1];
			int prev2 = nums2[index-1];

			// catch
			if(swapped)
				swap(prev1, prev2);

			// no swap.
			if(nums1[index] > prev1 && nums2[index] > prev2)
				ans = dp[index+1][0]; // pass 0 since we haven't swapped.

			// swap
			if(nums1[index] > prev2 && nums2[index] > prev1)
				ans = min(ans, 1 + dp[index+1][1]);

			dp[index][swapped] = ans;
		}
	}

	return dp[1][0];
}

int solveTabSO(vector<int> &nums1, vector<int> &nums2) {
	int n = nums1.size();
	int swap = 0, noswap = 0;
	int currswap = 0, currnoswap = 0;

	for(int index=n-1; index >= 1; index--) {
		for(int swapped=1; swapped >= 0; swapped--) {
			int ans = INT_MAX;

			int prev1 = nums1[index-1];
			int prev2 = nums2[index-1];

			// catch
			if(swapped) {
				int temp = prev2;
				prev2 = prev1;
				prev1 = temp;
			}

			// no swap.
			if(nums1[index] > prev1 && nums2[index] > prev2)
				ans = noswap; // pass 0 since we haven't swapped.

			// swap
			if(nums1[index] > prev2 && nums2[index] > prev1)
				ans = min(ans, 1 + swap);

			if(swapped)
				currswap = ans;
			else
				currnoswap = ans;
		}
		swap = currswap;
		noswap = currnoswap;
	}

	return min(swap, noswap);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	vector<int> nums1(n), nums2(n);

	for(int i = 0; i < n; i++)
	    cin >> nums1[i];

	for(int i = 0; i < n; i++)
	    cin >> nums2[i];

	nums1.insert(nums1.begin(), -1);
	nums2.insert(nums2.begin(), -1);

	bool swapped = 0; // it means that the previous indexes were swapped or not.
	cout << solveRec(nums1, nums2, 1, swapped) << endl;

	vector<vector<int>> dp(n+1, vector<int>(2, -1));
	cout << solveMem(nums1, nums2, 1, swapped, dp) << endl;

	cout << solveTab(nums1, nums2) << endl;

	cout << solveTabSO(nums1, nums2) << endl;

	return 0;
}