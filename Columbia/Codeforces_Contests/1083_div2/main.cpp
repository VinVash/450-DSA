#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int mx = 0, bad = -1;
    for (int i = 0; i < n; i++) {
        mx = max(mx, p[i]);
        if (mx == i + 1) {
            bad = i;
            break;
        }
    }

    if (bad != -1) {
        int pos = bad;
        for (int i = bad + 1; i < n; i++) {
            if (p[i] > p[pos]) pos = i;
        }
        swap(p[bad], p[pos]);
    }

    for (int x : p) cout << x << ' ';
    cout << '\n';
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