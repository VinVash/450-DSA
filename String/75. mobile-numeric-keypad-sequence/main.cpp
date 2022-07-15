#include <bits/stdc++.h>
using namespace std;

void printSequence(string s) {
	vector<string> sequences {"2","22","222", "3","33","333", "4","44","444", "5","55","555", "6","66","666",
		                      "7","77","777","7777",  "8","88","888", "9","99","999","9999"};

	int n = s.size();
	string output = "";

	for(int i = 0; i < n; i++) {
		if(s[i] == ' ')
			output += "0";
		else {
			int position = s[i] - 'A';
			output += sequences[position];
		}
	}

	cout << output << endl;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s; cin >> s;

	printSequence(s);

	return 0;
}