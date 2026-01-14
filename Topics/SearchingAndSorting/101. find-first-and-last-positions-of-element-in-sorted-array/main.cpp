#include <bits/stdc++.h>
using namespace std;

int first(vector<int> &nums, int x, int n) {
	int l = 0, r = n-1, res = -1;

	while(l <= r) {
		int mid = (l + r) / 2;
		if(nums[mid] > x)
			r = mid - 1;
		else if(nums[mid] < x)
			l = mid + 1;
		else {
			res = mid;
			r = mid - 1; // for moving further to the left.
		}
	}

	return res;
}

int last(vector<int> &nums, int x, int n) {
	int l = 0, r = n-1, res = -1;

	while(l <= r) {
		int mid = (l + r) / 2;
		if(nums[mid] > x)
			r = mid - 1;
		else if(nums[mid] < x)
			l = mid + 1;
		else {
			res = mid;
			l = mid + 1; // for moving further to the right.
		}
	}

	return res;
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

	int x; cin >> x;

	cout << first(nums, x, n) << " " << last(nums, x, n) << endl;

	return 0;
}