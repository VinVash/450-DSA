#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    
    ll zeroes = 0;
    ll ones = 0;
    
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        if (v == 0) zeroes++;
        if (v == 1) ones++;
    }
    
    ll ans = ones * (1LL << zeroes);
    cout << ans << endl;
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