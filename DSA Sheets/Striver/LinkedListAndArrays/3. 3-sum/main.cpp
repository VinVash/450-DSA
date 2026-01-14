#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int target = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    set<vector<int>> st;
    
    for(int i = 0; i < n; i++) {
        int newTarget = target - nums[i];
        
        int l = i+1, r = n-1;
        
        while(l < r) {

        	// cout << l << " " << r << endl;

            if(nums[l] + nums[r] > newTarget)
                r--;
            else if(nums[l] + nums[r] < newTarget)
                l++;
            else {
                st.insert({ nums[i], nums[l], nums[r] });
                // cout << "Inserting: " << nums[i] << ", " << nums[l] << ", " << nums[r] << endl;
                
                while(l+1 < n && nums[l+1] == nums[l])
                	l++;
                while(r-1 >= 0 && nums[r-1] == nums[r])
                	r--;

                l++; r--;
            }
            	
        }
    }

    for(auto itr: st) 
    	ans.push_back(itr);
    
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

	vector<vector<int>> ans = threeSum(nums);

	cout << ans.size() << endl;

	for(auto i: ans) {
		for(auto j: i)
			cout << j << " ";
		cout << endl;
	}




	return 0;
}