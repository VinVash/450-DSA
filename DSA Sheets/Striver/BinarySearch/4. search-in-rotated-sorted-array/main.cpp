#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n-1;
    
    while(l <= r) {
        int mid  = (l + r) / 2;
        
        if(nums[mid] == target)
            return mid;
        
        if(nums[l] <= nums[mid]) { // first half is sorted.
            if(nums[l] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        } else {
            if(nums[mid] < target && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    
    return -1;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}