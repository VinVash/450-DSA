#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n-2;
    
    while(l <= r) {
        int mid = (l + r) / 2;
        
        if(nums[mid] == nums[mid^1]) { // if mid is odd, then it will give you the previous even index.
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    
    return nums[l];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}