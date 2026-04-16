#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int cnt0 = 0;
    bool isodd = false;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        if (s.size() % 2 != 0) {
            isodd = true;
        }
        
        for (char c : s) {
            if (c == '0') cnt0++;
        }
    }
    
    if (isodd) {
        cout << n << endl;
    } else {
        if (cnt0 % 2 == 0) {
            cout << n << endl;
        } else {
            cout << n - 1 << endl;
        }
    }

}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    // solve();

	return 0;

}