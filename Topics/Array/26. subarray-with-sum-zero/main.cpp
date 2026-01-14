#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(vector<int> &nums) {
	set<int> res;
	int sum = 0;

	res.insert(sum);

	for(int i = 0; i < nums.size(); i++) {
		sum += nums[i];

		if(res.count(sum))
			return true;
		else
			res.insert(sum);
	}

	return false;
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

	if(subArrayExists(nums))
		cout << "Yes, subarray exists with sum 0" << endl;
	else
		cout << "No, there is no subarray with sum 0" << endl;


	return 0;
}