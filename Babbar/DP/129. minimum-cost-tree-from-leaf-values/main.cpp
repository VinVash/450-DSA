#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right) {
	// leaf node
    if(left == right)
        return 0;

    int ans = INT_MAX;

    for(int i = left; i < right; i++) {
        ans = min(ans, maxi[{ left, i }] * maxi[{ i+1, right }] + solve(arr, maxi, left, i) + solve(arr, maxi, i+1, right));
    }

    return ans;
}

int solveMem(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right, vector<vector<int>>& dp) {
	// leaf node
    if(left == right)
        return 0;

   if(dp[left][right] != -1)
   		return dp[left][right];

    int ans = INT_MAX;

    for(int i = left; i < right; i++) {
        ans = min(ans, maxi[{ left, i }] * maxi[{ i+1, right }] + solveMem(arr, maxi, left, i, dp) + solveMem(arr, maxi, i+1, right, dp));
    }

    return dp[left][right] = ans;
}

int mctFromLeafValues(vector<int>& arr) {
	int n = arr.size();
	map<pair<int, int>, int> maxi;

	for(int i = 0; i < n; i++) {
		maxi[{ i, i }] = arr[i];
		for(int j = i+1; j < n; j++) {
			maxi[{ i, j }] = max(arr[j], maxi[{ i, j-1 }]);
		}
	}

	// int ans = solve(arr, maxi, 0, n-1);

	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	int ans = solveMem(arr, maxi, 0, n-1, dp);

	return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}