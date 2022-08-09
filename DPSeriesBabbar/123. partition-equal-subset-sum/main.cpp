#include <bits/stdc++.h>
using namespace std;

int solveRec(int index, int arr[], int N, int target) {
	// base case.
	if(index >= N)
		return 0;
	if(target < 0)
		return 0;
	if(target == 0)
		return 1;

	int inc = solveRec(index+1, arr, N, target-arr[index]);
	int exc = solveRec(index+1, arr, N, target);

	if(inc == 1 || exc == 1)
		return 1;
	else
		return 0;
}

bool solveMem(int index, int arr[], int N, int target, vector<vector<int>> &dp) {
	// base case.
	if(index >= N)
		return 0;
	if(target < 0)
		return 0;
	if(target == 0)
		return 1;

	bool inc = solveMem(index+1, arr, N, target-arr[index], dp);
	bool exc = solveMem(index+1, arr, N, target, dp);

	dp[index][target] = inc || exc;
	return dp[index][target];
}

bool solveTab(int N, int arr[], int total) {
	// vector<vector<int>> dp(N+1, vector<int>(total+1, 0));

	vector<int> curr(total/2+1, 0);
	vector<int> next(total/2+1, 0);

	curr[0] = 1;
	next[0] = 1;

	// for(int i=0; i <= N; i++)
	// 	dp[i][0] = 1;

	for(int index=N-1; index >= 0; index--) {
		for(int target=0; target <= total/2; target++) {
			bool inc = 0;
			if(target - arr[index] >= 0)
				inc = next[target - arr[index]];
			bool exc = next[target];

			curr[target] = inc || exc;
		}
		next = curr;
	}
	return next[total/2];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int N; cin >> N;
	int arr[N];
	for(int i = 0; i < N; i++)
	    cin >> arr[i];

	int total = 0;
	for(int i=0; i < N; i++)
		total += arr[i];

	if(total % 2 == 1)
		return 0;

	int target = total / 2;

	// cout << solveRec(0, arr, N, target) << endl;

	// vector<vector<int>> dp(N+1, vector<int>(target+1, -1));
	// cout << solveMem(0, arr, N, target, dp) << endl;

	cout << solveTab(N, arr, total) << endl;

	return 0;
}