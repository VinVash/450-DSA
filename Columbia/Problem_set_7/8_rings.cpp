#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    bool f = false;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            f = true;
            if (i >= n /2) {
                cout << 1 << " " << i+1 << " " << 1 << " " << i << endl;
            } else {
                cout << i+1 << " " << n << " " << i+2 << " " << n << endl;
            }
            break;
        }
    }
    
    if (!f) {
        cout << 1 << " " << n-1 << " " << 2 << " " << n << endl;
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

    return 0;
}