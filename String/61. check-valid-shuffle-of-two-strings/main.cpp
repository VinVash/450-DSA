#include <bits/stdc++.h>
using namespace std;

bool validShuffle(string s1, string s2, string result) {
	if(result.size() != s1.size() + s2.size())
		return false;

	vector<char> ss1(s1.begin(), s1.end());
	vector<char> ss2(s2.begin(), s2.end());
	vector<char> r(result.begin(), result.end());

	sort(ss1.begin(), ss1.end());
	sort(ss2.begin(), ss2.end());
	sort(r.begin(), r.end());

	int i = 0, j = 0; // iterators for ss1 and ss2.
	int k = 0; // iterators for r.

	while(i < ss1.size() || j < ss2.size()) {
		if(ss1[i] == r[k]) {
			i++; k++;
		} else if(ss2[j] == r[k]) {
			j++; k++;
		} else
			return false;
	}

	if(i < ss1.size() || j < ss2.size()) {
		return false;
	}

	return true;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s1, s2, result;
	cin >> s1 >> s2 >> result;

	if(validShuffle(s1, s2, result))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;


	return 0;
}