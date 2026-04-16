#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll pw(ll a, ll e) {
    ll r =1;
    while (e >0) {
        if (e &1) r = (r *a) %mod;
        a = (a *a) %mod;
        e >>= 1;
    }
    return r;
}

void solve() {
    ll d; cin >> d;
    int q; cin >> q;

    vector<ll> p;
    vector<int> c;

    ll x = d;
    for (ll i =2; i*i <=x; i++) {
        if (x %i) continue;
        int k =0;
        while (x %i ==0) {
            x /= i;
            k++;
        }
        p.push_back(i);
        c.push_back(k);
    }
    if (x > 1) {
        p.push_back(x);
        c.push_back(1);
    }

    int s = 0;
    for (int i = 0; i < c.size(); i++) s +=c[i];

    vector<ll> f(s+1), rf(s+1);
    f[0] = 1;
    for (int i =1; i <=s; i++) f[i] = (f[i-1] *i) %mod;
    rf[s] = pw(f[s], mod-2);
    for (int i = s-1; i >=0; i--) rf[i] = (rf[i+1] * (i+1)) %mod;

    while (q--) {
        ll u, v;
        cin >> u >> v;

        int su = 0, sv = 0;
        ll du = 1, dv = 1;

        for (int i = 0; i < p.size(); i++) {
            int cu =0, cv =0;
            while (u % p[i] ==0) {
                u /= p[i];
                cu++;
            }
            while (v % p[i] ==0) {
                v /= p[i];
                cv++;
            }

            if (cu >cv) {
                int t = cu -cv;
                su +=t;
                du = (du * rf[t]) %mod;
            } else if (cv > cu) {
                int t = cv -cu;
                sv += t;
                dv = (dv * rf[t]) %mod;
            }
        }

        ll ans = f[su];
        ans = (ans * f[sv]) % mod;
        ans = (ans * du) % mod;
        ans = (ans * dv) % mod;
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();

    return 0;
}
