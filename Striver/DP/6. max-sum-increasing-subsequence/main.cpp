#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n) {
	vector<int> dp(n);

	for(int i = 0; i < n; i++)
		dp[i] = arr[i];

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(arr[i] > arr[j] && arr[i] + dp[j] > dp[i]) {
				dp[i] = arr[i] + dp[j];
			}
		}
	}

	int maxi = INT_MIN;
	for(int i = 0; i < n; i++) {
		if(dp[i] > maxi)
			maxi = dp[i];
	}

	return maxi;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}