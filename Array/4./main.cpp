#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &nums, int n) {
    int l = 0, r = n-1;
    int i = 0;
    
    while(i <= r) {
        if(nums[i] == 0) {
            swap(nums[l], nums[i]);
            l++; i++;
        } else if (nums[i] == 1) {
            i++;
        } else {
            swap(nums[r], nums[i]);
            r--;
        }
    }
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    vector<int> nums {2, 2, 1, 1, 1, 0};
    sort012(nums, nums.size());

    for(int i = 0; i < nums.size(); i++)
    	cout << nums[i] << " ";
    cout << endl;

	return 0;
}