#include <bits/stdc++.h>
using namespace std;

void allPermutations(string s, string ans) {
	if(s.size() == 0)
		cout << ans << " ";

	for(int i = 0; i < s.size(); i++) {
		char ch = s[i];
		string left_substr = s.substr(0, i);
		string right_substr = s.substr(i+1);
		string rest = left_substr + right_substr;
		allPermutations(rest, ans+ch);
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s; cin >> s;
	string ans;

	allPermutations(s, ans);

	return 0;
}