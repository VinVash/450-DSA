#include <bits/stdc++.h>
using namespace std;

// Declare target and ans variable globally.

int target;

vector<vector<int>> ans;

void solveRec(vector<int>& arr, int i, int sum, vector<int> op) {

    if(i >= arr.size())
        return;

    if(arr[i] + sum == target) {
        op.push_back(arr[i]);
        ans.push_back(op);
        return;
    }

    if(arr[i] + sum < target) {
        vector<int> op1 = op;
        vector<int> op2 = op;

        op2.push_back(arr[i]);
        solveRec(arr, i, sum + arr[i], op2);
        solveRec(arr, i + 1, sum, op1);
    } else {
        solveRec(arr, i + 1, sum, op); // call for the next index
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int required_target) {
    ans.clear(); //clear global array, make to sure that no garbage value is present in it

    target = required_target; // give target what he wants 
    vector<int> op; // op array to try all possible combination
    sort(candidates.begin(),candidates.end()); // sort the array in ascending order
    solveRec(candidates, 0, 0, op); // call function

    return ans; // return the final answer array
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