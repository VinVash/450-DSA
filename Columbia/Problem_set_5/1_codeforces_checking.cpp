#include <bits/stdc++.h>
using namespace std;

void solve() {
    char ch; cin >> ch;

    string s = "codeforces";
    if(s.find(ch) != string::npos) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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