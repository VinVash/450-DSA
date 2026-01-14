#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
	int n = nums.size();

    int curr = nums[0];
    int max_sum = nums[0];

    for(int i = 1; i < n; i++) {
        if(curr < 0)
            curr = 0;

        curr += nums[i];

        if(curr > max_sum)
            max_sum = curr;

    }

    return max_sum;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}