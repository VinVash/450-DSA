#include <bits/stdc++.h>
using namespace std;

int check(string s, bool a_win) {
	int scoreA = 0, scoreB = 0;
	int remA = 5, remB = 5;

	for(int i = 0; i < 10; i++) {
		if(i % 2 == 0 ) { // team A
			remA--;
			if(s[i] == '1') {
				scoreA++;
			} else if(s[i] == '?') {
				if(a_win) scoreA++;
			}
		} else {
			remB--;
			if(s[i] == '1') {
				scoreB++;
			} else if(s[i] == '?') {
				if(!a_win) scoreB++;
			}
		}

		if(scoreA > scoreB + remB) return i+1;

		if(scoreB > scoreA + remA) return i+1;
	}

	return 10;
}

void solve() {
	string s; cin >> s;

	int op1 = check(s, true); // make A win

	int op2 = check(s, false); // make B win

	cout << min(op1, op2) << endl;

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