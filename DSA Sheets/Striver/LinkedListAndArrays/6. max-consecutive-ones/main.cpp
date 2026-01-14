#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    
    int i = 0;
    int j = i;
    
    while(j < n) {

        int temp = 1;
        while(nums[j+1] == 1) {
            temp++;
            j++;
        }

        ans = max(ans, temp);

        i = j+1;
        while(i < n && nums[i] != 1)
            i++;
        j = i;
    }
    
    return ans;
}

int findMaxConsecutiveOnes2(vector<int> &nums) {
	int n = nums.size();
    int ans = 0;
    int temp = 0;
    
    for(int i = 0; i < n; i++) {
    	if(nums[i] == 1)
    		temp++;
    	else
    		temp = 0;

    	ans = max(ans, temp);
    }
    
    return ans;
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

    int ans = findMaxConsecutiveOnes2(nums);

    cout << ans << endl;

	return 0;
}