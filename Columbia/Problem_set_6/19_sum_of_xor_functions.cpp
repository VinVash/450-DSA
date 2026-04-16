#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;

void solve() {
    int n; cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> pref(n+1, 0);
    for (int i = 1; i <=n; i++) {
        pref[i] = pref[i-1] ^ a[i-1];
    }

    ll ans = 0;
    for (int bit = 0; bit < 30; bit++) {
        ll cnt[2] = {0, 0};
        ll sumidx[2] = {0, 0};
        ll p2 = (1LL << bit) % MOD;
        
        for (int i = 0; i <= n; i++) {
            int b = (pref[i] >> bit) & 1;
            
            ll cont = (1LL * i * cnt[1- b] - sumidx[1- b]) % MOD;
            cont = (cont + MOD) % MOD; // neg mod
            
            ll add = (cont * p2) % MOD;
            ans = (ans + add) % MOD;
            
            cnt[b]++;
            sumidx[b] = sumidx[b] + i;
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