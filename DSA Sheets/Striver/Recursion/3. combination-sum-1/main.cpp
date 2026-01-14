#include <bits/stdc++.h>
using namespace std;

// Declare target and ans variable globally.

void solve(vector<int>& candidates, int i, int target, vector<int>& temp, vector<vector<int>>& ans) {
    if(i >= candidates.size())  
        return;

    if(candidates[i] == target) {
        temp.push_back(candidates[i]);
        ans.push_back(temp);
        return;
    }

    if(candidates[i] < target) {
        vector<int> temp1 = temp, temp2 = temp;

        temp2.push_back(candidates[i]);

        solve(candidates, i, target-candidates[i], temp2, ans);
        solve(candidates, i+1, target, temp1, ans);
    } else {
        solve(candidates, i+1, target, temp, ans);
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;

    vector<int> temp; // to test the combinations

    sort(candidates.begin(), candidates.end());
    solve(candidates, 0, target, temp, ans); // i->0, sum->0

    return ans;
}
int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, x; cin >> n >> x;
	vector<int> nums(n);
	for(int i = 0; i < n; i++)
	    cin >> nums[i];

	vector<vector<int>> ans = combinationSum(nums, x);
	cout << ans.size() << endl;
	for(auto i: ans) {
		for(auto j: i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}