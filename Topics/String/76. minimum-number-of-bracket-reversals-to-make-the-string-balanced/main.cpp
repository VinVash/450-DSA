#include <bits/stdc++.h>
using namespace std;

int minReversals1(string s) {
	int n = s.size();

	if(n % 2 == 1)
		return -1;

	stack<char> stk;
	for(int i = 0; i < n; i++) {
		if(s[i] == '}' && !stk.empty()) {
			if(stk.top() == '{')
				stk.pop();
			else
				stk.push(s[i]);
		} else {
			stk.push(s[i]);
		}
	}

	int reduced_size = stk.size();
	int res = 0; // opening brackets at the end of the stack.
	while(!stk.empty() && stk.top() == '{') {
		stk.pop();
		res++;
	}

	// till here, res contains no. of opening brackets at the end.
	// ceil(m/2) + ceil(n/2) = (reduced_size / 2) + (n % 2).
	return (reduced_size / 2 + res % 2);
}

int minReversals2(string s) {
	stack<char> stk;
	int res = 0;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '{')
			stk.push(s[i]);
		else {
			if(!stk.empty())
				stk.pop();
			else {
				stk.push('{'); // changed '}' into '{' and then pushed it into the stack.
				res++;
			}
		}
	}

	if(stk.size() % 2 == 1)
		return -1;

	res += stk.size() / 2;
	return res;
}

int minReversals3(string s) {
	int n = s.size();

	if(n % 2 == 1)
		return -1;

	int left_brace = 0, right_brace = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '{')
			left_brace++;

		else {
			if(left_brace == 0)
				right_brace++;
			else
				left_brace--;
		}
	}

	int res = ceil(left_brace / 2.0) + ceil(right_brace / 2.0);
	return res;
}

int minReversals4(string s) {
	int n = s.size();
	int temp = 0, res = 0;

	if(n % 2 == 1)
		return -1;

	for(int i = 0; i < n; i++) {
		if(s[i] == '{')
			temp++;
		else {
			if(temp == 0) {
				res++;
				temp++;
			} else {
				temp--;
			}
		}
	}

	if(temp > 0)
		res += temp / 2;

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    string s; cin >> s;

	cout << minReversals1(s) << endl;
	cout << minReversals2(s) << endl;
	cout << minReversals3(s) << endl;
	cout << minReversals4(s) << endl;

	return 0;
}