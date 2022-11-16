#include <bits/stdc++.h>
using namespace std;

void solveRec(int index, vector<int> &nums, vector<vector<int>> &ans) {
    int n = nums.size();
    
    if(index == n) {
        ans.push_back(nums);
    }
    
    for(int i = index; i < n; i++) {
        swap(nums[index], nums[i]);
        solveRec(index+1, nums, ans);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    
    solveRec(0, nums, ans);
    return ans;
}

// 2nd approach:

// void solveRec(vector<int> &temp, vector<int> &nums, vector<vector<int>> &ans, vector<int> &freq) {
//     if(temp.size() == nums.size()) {
//         ans.push_back(temp);
//         return;
//     }
    
//     for(int i = 0; i < nums.size(); i++) {
//         if(!freq[i]) {
//             temp.push_back(nums[i]);
//             freq[i] = 1;
//             solveRec(temp, nums, ans, freq);
//             freq[i] = 0;
//             temp.pop_back();
//         }
//     }
// }

// vector<vector<int>> permute(vector<int>& nums) {
//     vector<vector<int>> ans;
//     vector<int> temp;
    
//     int n = nums.size();
    
//     vector<int> freq(n, 0);
    
//     solveRec(temp, nums, ans, freq);
    
//     return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}