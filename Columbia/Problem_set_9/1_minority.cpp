#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    string s; cin >> s;
    
    int z = 0, o = 0;
    
    for (int i =0; i <s.size(); i++) {
        if (s[i] =='0') z++;
        else o++;
    }
    
    if (z ==o) {
        if (z ==0) {
            cout << 0<< endl;
        } else {
            cout << z-1 << endl;
        }
    } else {
        cout << min(z,o) << endl;
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