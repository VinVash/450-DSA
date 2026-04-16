#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    
    vector<ll> x;
    vector<ll> y;

    for (int i = 0; i < 2 * n; i++) {
        ll u, v; cin >> u >> v;
        if (u == 0) {
            y.push_back(abs(v));
        } else {
            x.push_back(abs(u));
        }
    }
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    double ans = 0;

    for (int i = 0; i <n; i++) {
        ans += sqrt(1.0 *x[i] *x[i] + 1.0 *y[i] *y[i]);
    }
    cout << fixed << setprecision(15) << ans << endl;
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