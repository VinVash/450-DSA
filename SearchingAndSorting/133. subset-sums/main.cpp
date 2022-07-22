#include <bits/stdc++.h>
using namespace std;

// Returns true if there is a subset of nums[]
// with sum equal to given sum
bool isSubsetSum(vector<int> &nums, int n, int sum) {
	// The value of subset[i][j] will be true if
	// there is a subset of nums[0..j-1] with sum equal to i.
	bool subset[n + 1][sum + 1];

	// If sum is 0, then answer is true (empty subset).
	for (int i = 0; i <= n; i++)
		subset[i][0] = true;

	// If sum is not 0 and nums is empty,
	// then answer is false
	for (int i = 1; i <= sum; i++)
		subset[0][i] = false;

	// Fill the subset table in bottom up manner
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < nums[i - 1])
				subset[i][j] = subset[i - 1][j]; // iska vohi haal hai jo iske pehle vaale ka hai.
			if (j >= nums[i - 1])
				subset[i][j] = subset[i - 1][j]
							|| subset[i - 1][j - nums[i - 1]];
		}
	}

	/* // uncomment this code to print table
	for (int i = 0; i <= n; i++)
	{
	for (int j = 0; j <= sum; j++)
		printf ("%4d", subset[i][j]);
	cout <<"\n";
	}*/

	return subset[n][sum];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> nums { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = nums.size();

	if (isSubsetSum(nums, n, sum) == true)
		cout <<"Found a subset with given sum";
	else
		cout <<"No subset with given sum";

	return 0;
}
