#include <bits/stdc++.h>
using namespace std;

void fill(int ind, string& s, int k, set<string>& st) {

	if(ind >= s.size()) {
		st.insert(s);
		return;
	}

	if(s[ind] != '*') {
		fill(ind+1, s, k, st);
	} else {
		// s[ind] is '*'
		int n = s.size();
		string pre = s.substr(0, ind);
		string post = "";
		if(ind+1 < s.size()) post = s.substr(ind+1, n-ind-1);
		for(int i = 0; i<= k; i++) {
			string t(i, 'b');
			string final = pre + t + post;
			fill(ind+i, final, k, st);
		}
	}

}

void solve() {
	int n;
	long long k, x;
	cin >> n >> k >> x;
	x -= 1; // index should be 0 based

	string s; cin >> s;

	set<string> st;
	string res = "";

	for(int i = n-1;i >= 0; i--) {
		if(s[i] == 'a') {
			res += 'a';
		} else {
			int count = 0;
			while(i >= 0 && s[i] == '*') {
				count++;
				i--;
			}

			i++;

			long long limit = (long long)count * k + 1; // no. of options for this group

			long long b_needed = x % limit;
			x /= limit;

			for(int j = 0; j < b_needed; j++) {
				res += 'b';
			}
		}
	}

	reverse(res.begin(), res.end());
	cout << res << endl;

	// fill(0, s, k, st);

	// auto it = next(st.begin(), x-1);
	// cout << *it << endl;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
    	solve();
    }


    return 0;

}
