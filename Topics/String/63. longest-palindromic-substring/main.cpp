#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, string s) {
	if(i == j) // if indices are same, then single char is always a palindrome.
		return 1;

	if(j - i == 1) {
		if(s[i] == s[j])
			return 1;
		else
			return 0;
	}

	if(s[i] == s[j] && solve(i+1, j-1, s) == 1) {
		return 1;
	} 
	
	return 0;
}

string longestPalindromicSubstring(string s) {
	int n = s.size();
	int start_index = 0, max_len = 0;

	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			int temp = solve(i, j, s);
			if(temp == 1) {
				if(j-i+1 > max_len) {
					max_len = max(max_len, j-i+1);
					start_index = i;
				}
			}
		}
	}
	return s.substr(start_index, max_len);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    string s; cin >> s;
    cout << longestPalindromicSubstring(s) << endl;

	return 0;
}