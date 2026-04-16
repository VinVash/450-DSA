#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if(s.size() == 1) {
        cout << "NO" << endl;
        return;
    }

    if(s.size() == 2) {

        if(s[0] < s[1]) {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << s[0] << " " << s[1] << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    cout << 2 << endl;
    cout << s[0] << " " << s.substr(1) << endl;
    
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