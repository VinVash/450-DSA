#include <bits/stdc++.h>
using namespace std;

int count(const string& s) {
    int counter = 0;
    string match = "abacaba";
    for (int i = 0; i <= (int)s.length() - 7; i++) {
        if (s.substr(i, 7) == match) {
            counter++;
        }
    }
    return counter;
}

// bool check(string s, int ind, string match) {
// 	for(int i = 0; i < 7; i++) {
// 		if(s[ind+i] == match[i]) continue;
// 		else return false;
// 	}

// 	return true;

// }

// bool check(string& s, int ind, string match, int count) {
// 	for(int i = 0; i < 7; i++) {
// 		if(s[ind+i] == match[i]) continue;
// 		else if(s[ind+i] == '?') {
// 			if(count == 0) s[ind+i] = match[i];
// 			else s[ind+i] = 'd';
// 		} else {
// 			return false;
// 		}
// 	}

// 	return true;
// }

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	string match = "abacaba";

	for(int i = 0; i< n-6; i++) { // max is n-7 -> good
		string temp = s;
		bool flag = true; // to track if it's possible

		for (int j = 0; j < 7; j++) {
            if (temp[i+j] != '?' && temp[i+j] != match[j]) {
                flag = false;
                break;
            }
            temp[i+j] = match[j];
        }

        if (flag) {
            for (int k = 0; k < n; k++) {
                if (temp[k] == '?') {
                    temp[k] = 'd';
                }
            }

            if (count(temp) == 1) {
                cout << "Yes" << endl;
                cout << temp << endl;
                return;
            }
        }
	}

	
	cout << "No" << endl;
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