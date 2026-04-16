#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if(n != 5) {
        cout << "NO" << endl;
        return;
    }

    sort(s.begin(), s.end());
    string org = "Timur";
    sort(org.begin(), org.end());

    if(org == s) {
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