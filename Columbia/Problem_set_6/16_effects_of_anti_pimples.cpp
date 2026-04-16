#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;

void solve() {
    int n; cin >> n;
    
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }

    sort(a.rbegin(), a.rend());

    vector<ll> p2(n+1, 1);
    for (int i = 1; i <=n; i++) {
        p2[i] = (p2[i-1] * 2) % MOD;
    }

    vector<vector<int>> divs(n+1);
    for (int i = 1; i <=n; i++) {
        for (int j = i; j <=n; j += i) {
            divs[j].push_back(i);
        }
    }

    vector<bool> seen(n+1, false);
    int cnt = 0;
    ll ans = 0;

    for (int i = 0; i< n; i++) {
        int val = a[i].first;
        int idx = a[i].second;

        int prev = cnt;
        for (int j = 0; j < divs[idx].size(); j++) {
            int d = divs[idx][j];
            if (!seen[d]) {
                seen[d] = true;
                cnt++;
            }
        }

        if (cnt > prev) {
            ll ways = (p2[n-prev] - p2[n-cnt] + MOD) % MOD;
            ans = (ans + val*ways) % MOD;
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

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve();

    return 0;
}