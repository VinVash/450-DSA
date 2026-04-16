#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int pos_a = s.find('A');
    int pos_b = s.rfind('B');
    
    if (pos_a != string::npos && pos_b != string::npos && pos_a < pos_b) {
        cout << pos_b - pos_a << endl;
    } else {
        cout << 0 << endl;
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