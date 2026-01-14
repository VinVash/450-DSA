#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int ans = nums[0];
    int n = nums.size();
    
    vector<int> maxx(n);
    vector<int> minn(n);
    
    maxx[0] = minn[0] = ans;
    for(int i = 1; i < n; i++) {
        if(nums[i] > 0) {
            maxx[i] = max(nums[i], maxx[i-1] * nums[i]);
            minn[i] = min(nums[i], minn[i-1] * nums[i]);
        } else {
            minn[i] = min(nums[i], maxx[i-1] * nums[i]);
            maxx[i] = max(nums[i], minn[i-1] * nums[i]);
        }
        
        ans = max(ans, maxx[i]);
    }
    
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}