#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums) {
	int n = nums.size();

	vector<int> LIS(n, 1); // since every element is an increasing subsequence.

	for(int i=n-1; i >= 0; i--) {
		for(int j=i+1; j < n; j++) {
			if(nums[j] > nums[i]) {
				LIS[i] = max(LIS[i], 1 + LIS[j]);
			}
		}
	}

	return *max_element(LIS.begin(), LIS.end());
}

int solveRec(int n, vector<int> &a, int curr, int prev) {
	// base case.
	if(curr == n) {
		return 0;
	}

	// include
	int inc = 0;
	if(prev == -1 || a[curr] > a[prev])
		inc = 1 + solveRec(n, a, curr+1, curr);

	// exclude
	int exc = 0 + solveRec(n, a, curr+1, prev);

	return max(inc, exc);
}

int solveMem(vector<int> &nums, int n, int curr, int prev, vector<vector<int>> &dp) {
    if(curr == n) {
        return 0; //reached the end index.
    }
    
    if(dp[curr][prev+1] != -1)
        return dp[curr][prev+1];
    
    int inc = 0, exc = 0;
//         include
    if(prev == -1 || nums[curr] > nums[prev]) {
         inc = 1 + solveMem(nums, n, curr+1, curr, dp);
    }
    
//         exclude
    exc = 0 + solveMem(nums, n, curr+1, prev, dp);
    
    return dp[curr][prev+1] = max(inc, exc);
}

int solveTab(int n, vector<int> &a) {
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

	for(int curr=n-1; curr >= 0; curr--) {
		for(int prev=curr-1; prev >= -1; prev--) {
			// include
			int inc = 0;
			if(prev == -1 || a[curr] > a[prev])
				inc = 1 + dp[curr+1][curr+1]; // second curr+1 in order to bring it in sync with prev's indices, i.e. accessing a specific index by adding +1.

			// exclude
			int exc = 0 + dp[curr+1][prev+1];

			dp[curr][prev+1] = max(inc, exc);
		}
	}
	return dp[0][0];
}

int solveTabSO(int n, vector<int> &a) {
	vector<int> currRow(n+1, 0);
	vector<int> nextRow(n+1, 0);

	for(int curr=n-1; curr >= 0; curr--) {
		for(int prev=curr-1; prev >= -1; prev--) {
			// include
			int inc = 0;
			if(prev == -1 || a[curr] > a[prev])
				inc = 1 + nextRow[curr+1];

			// exclude
			int exc = 0 + nextRow[prev+1];

			currRow[prev+1] = max(inc, exc);
		}
		nextRow = currRow;
	}
	return nextRow[0];
}

// DP with Binary Search
int solveOptimal(int n, int a[]) {
	if(n == 0)
		return 0;

	vector<int> ans;
	ans.push_back(a[0]);

	for(int i=1; i < n; i++) {
		if(a[i] > ans.back())
			ans.push_back(a[i]);
		else {
			// find index of just greater element
			int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
			ans[index] = a[i];
		}
	}

	return ans.size();
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	// vector<vector<int>> dp(n, vector<int>(n+1, -1));
	// cout << solveMem(n, a, 0, -1, dp) << endl;

	// cout << solveTab(n, a) << endl;

	// cout << solveOptimal(n, a) << endl;

	return 0;
}