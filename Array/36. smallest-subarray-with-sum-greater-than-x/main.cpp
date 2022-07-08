#include <bits/stdc++.h>
using namespace std;

int smallestSubWithSum(vector<int> &nums, int n, int x) {
	// initialising min_length with the max value possible.
	int min_length = n+1, current_sum = 0;

	int l = 0, r = 0;

	while(r < n) {
		// till current_sum passes x.
		while(current_sum <= x && r < n) {
			current_sum += nums[r];
			r++;
		}

		// once the current_sum passes x.
		while(current_sum > x && l < n) {
			if(r - l < min_length)
				min_length = r - l;

			current_sum -= nums[l];
			l++;
		}
	}

	return min_length;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, x;
	cin >> n >> x;
	vector<int> nums(n);

	for(int i = 0; i < n; i++)
	    cin >> nums[i];

	cout << smallestSubWithSum(nums, n, x) << endl;


	return 0;
}