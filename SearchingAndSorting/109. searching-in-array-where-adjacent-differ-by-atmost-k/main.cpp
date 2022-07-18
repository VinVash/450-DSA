#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int k, int x) {
	int n = nums.size();
	int i = 0;

	while(i < n) {
		if(nums[i] == x)
			return i;
		else {
			int diff = nums[i] - x;
			i += max(1, abs(diff/k));
		}
	}
	return -1;
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

    int k, x;
    cin >> k >> x;

    cout << search(nums, k , x);

	return 0;
}