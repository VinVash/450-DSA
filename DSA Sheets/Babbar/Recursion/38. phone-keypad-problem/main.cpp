#include <bits/stdc++.h>
using namespace std;

void solve(string digits, string output, int index, vector<string> &res, vector<string> mapping) {
	// base case.
	if(index >= digits.size()) {
		res.push_back(output);
		return;
	}

	int number = digits[index] - '0';
	string value = mapping[number];

	for(int c = 0; c < value.size(); c++) { // c -> character
		output.push_back(value[c]);
		solve(digits, output, index+1, res, mapping);
		output.pop_back();
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> res;
	string output;
	int index = 0;
	vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl" "mno", "pqrs", "tuv", "wxyz"};
	solve(digits, output, index, res, mapping);

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string digits = "23";
	vector<string> ans = letterCombinations(digits);

	for(auto i: ans)
		cout << i << " ";
	cout << endl;

	return 0;
}