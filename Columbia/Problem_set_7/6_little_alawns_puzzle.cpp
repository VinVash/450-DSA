#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vector<bool> vis(n, false);
    long long ans = 1;
    long long mod = 1000000007;
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans = (ans * 2) % mod;
            int curr = i;
            while (!vis[curr]) {
                vis[curr] = true;
                curr = pos[b[curr]];
            }
        }
    }
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