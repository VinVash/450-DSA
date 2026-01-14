#include <bits/stdc++.h>
using namespace std;

void reverseRec(string &s, int l, int r) {
	// base case.
	if(l > r)
		return;

	swap(s[l], s[r]);
	reverseRec(s, l+1, r-1);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s; cin >> s;

	reverseRec(s, 0, s.size()-1);

	cout << s << endl;

	return 0;
}