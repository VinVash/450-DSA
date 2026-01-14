#include <bits/stdc++.h>
using namespace std;

void printDuplicate(string s) {
	unordered_map<char, int> duplicates;

	for(int i = 0; i < s.size(); i++)
		duplicates[s[i]]++;

	for(auto it: duplicates) {
		if(it.second > 1)
			cout << it.first << ": " << it.second << endl;
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s; cin >> s;

	printDuplicate(s);

	return 0;
}