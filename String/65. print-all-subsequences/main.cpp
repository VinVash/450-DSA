#include <bits/stdc++.h>
using namespace std;

void printAllSubsequences(string input, string output) {
	if(input.empty()) {
		cout << output << endl;
		return;
	}

	printAllSubsequences(input.substr(1), output + input[0]);
	printAllSubsequences(input.substr(1), output);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s; cin >> s;

	string input = s;
	string output = "";

	printAllSubsequences(input, output);

	return 0;
}