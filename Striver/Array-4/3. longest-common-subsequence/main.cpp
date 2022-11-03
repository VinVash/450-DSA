#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st;
    
    for(auto num: nums)
        st.insert(num);
    
    int longestStreak = 0;
    
    for(auto num: st) {

        if(st.find(num-1) == st.end()) {
            int currentNum = num;
            int currentStreak = 1;
            
            while(st.find(currentNum+1) != st.end()) {
                currentNum += 1;
                currentStreak += 1;
            }
            
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    
    return longestStreak;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> nums {100, 4, 200, 1, 3, 2};
	int n = nums.size();

	int ans = longestConsecutive(nums);
	cout << ans << endl;

	return 0;
}