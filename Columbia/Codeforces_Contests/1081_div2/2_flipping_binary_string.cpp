#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int ones = 0, zeroes = 0;
    for(char x: s) {
        if(x == '1') ones++;
        else zeroes++;
    }

    if(ones % 2 == 0) {
        cout << ones << endl;

        for(int i = 0; i < n; i++) {
            if(s[i] == '1') cout << i+1 << " ";
        }
        cout << endl;

    } else if (zeroes % 2 != 0) {
        cout << zeroes << endl;
        for(int i = 0;i < n; i++) {
            if(s[i] == '0') {
                cout << i+1 << " ";
            }
        }
        cout << endl;

    } else {
        cout << -1 << endl;
    }



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

    // solve();

    return 0;
}