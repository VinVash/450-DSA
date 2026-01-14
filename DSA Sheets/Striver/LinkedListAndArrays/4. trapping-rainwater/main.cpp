#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    
    vector<int> left(n);
    vector<int> right(n);
    
    int leftmax = height[0];
    for(int i = 1; i < n; i++) {
        left[i] = leftmax;
        leftmax = max(leftmax, height[i]);
    }
    left[0] = 0;
    
    int rightmax = height[n-1];
    for(int i = n-2; i >= 0; i--) {
        right[i] = rightmax;
        rightmax = max(rightmax, height[i]);
    }
    right[n-1] = 0;

    for(auto i : left)
    	cout << i << " ";
    cout << endl;

    for(auto i : right)
    	cout << i << " ";
    cout << endl;
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int mini = min(left[i], right[i]);
        if(mini > height[i]) {
            ans += (mini - height[i]);
        }
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

	int ans = trap(nums);
	cout << ans << endl;

	return 0;
}