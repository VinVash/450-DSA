#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector < int > arr) {

    int n = arr.size();
    
    unordered_map<int, int> mp;
       
    int total = 0;
    int ans = 0;
    mp[total] = -1;
    for(int i = 0; i < n; i++) {
        total += arr[i];
        if(mp.find(total) != mp.end())
            ans = max(ans, i - mp.at(total));
        else
            mp[total] = i;
    }
    
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> nums {2, -2, 4, -4};
	int ans = LongestSubsetWithZeroSum(nums);

	cout << ans << endl;

	return 0;
}