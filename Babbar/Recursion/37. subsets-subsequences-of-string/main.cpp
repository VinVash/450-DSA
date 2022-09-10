#include <bits/stdc++.h>
using namespace std;

// Function for subsets.
void solveRec(vector<int> nums, vector<int> output, int index, vector<vector<int>> &res) {
	// base case
	if(index >= nums.size()) {
		res.push_back(output);
		return;
	}

	// exclude
	solveRec(nums, output, index+1, res);

	// include
	int element = nums[index];
	output.push_back(element);
	solveRec(nums, output, index+1, res);
}

// Function for subsequences.
void solve(string str, string output, int index, vector<string> &ans) {
	// base case.
	if(index >= str.size()) {
		ans.push_back(output);
		return;
	}

	// exclude
	solve(str, output, index+1, ans);

	// include
	char element = str[index];
	output.push_back(element);
	solve(str, output, index+1, ans);
}

vector<vector<int>> subsets(vector<int> &nums) {
	vector<vector<int>> res;
	vector<int> output;

	int index = 0;
	solveRec(nums, output, index, res);
	return res;
}

vector<string> subsequences(string str) {
	vector<string> res;
	string output = "";
	int index = 0;
	solve(str, output, index, res);
	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> nums = {1, 2, 3};
	int n = nums.size();

	string str = "abc";

	vector<vector<int>> res = subsets(nums);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	vector<string> subseq = subsequences(str);
	for(int i = 0; i < subseq.size(); i++)
		cout << subseq[i] << " ";
	cout << endl;

	return 0;
}