#include <bits/stdc++.h>
using namespace std;

void solveRec(int i, int sum, vector<vector<int>> &ans, vector<int> &arr) {

    if(i == arr.size()) {
        ans.push_back(sum);
        return;
    }
        
    int inc = sum + arr[i];
    int exc = sum;

    
    solveRec(i+1, exc, ans, arr);
    solveRec(i+1, inc, ans, arr);
}


vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	
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