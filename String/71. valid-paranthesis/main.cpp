#include <bits/stdc++.h>
using namespace std;

bool validParanthesis(string s) {
	stack<int> stk;

	unordered_map<char, char> matcher;
	matcher[')'] = '(';
	matcher[']'] = '[';
	matcher['}'] = '{';

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			stk.push(s[i]);
		else {
			if(stk.empty())
				return false;
			else if(stk.top() == matcher[s[i]])
				stk.pop();
			else
				return false;
		}
	}

	if(stk.size())
		return false;

	return true;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s; cin >> s;

	if(validParanthesis(s))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}