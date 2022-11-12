#include <bits/stdc++.h>
using namespace std;

void solveRec(vector<int> temp, vector<vector<int>> &ans, vector<int> &nums, int i) {
    if(i == nums.size()) {
        ans.push_back(temp);
        return;
    }
    
    solveRec(temp, ans, nums, i+1);
    
    temp.push_back(nums[i]);
    solveRec(temp, ans, nums, i+1);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    
    vector<vector<int>> ans;
    int i = 0;
    vector<int> temp;
    
    solveRec(temp, ans, nums, i);

    set<vector<int>> st;
    for(auto j: ans) {
        sort(j.begin(), j.end());
        st.insert(j);
    }

    vector<vector<int>> res(st.begin(), st.end());
    
    return res;
    
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

    vector<vector<int>> ans = subsetsWithDup(nums);
    for(auto i: ans) {
        for(auto j: i)
            cout << j << " ";
        cout << endl;
    }


    return 0;
}
