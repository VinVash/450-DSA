#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll gcd(ll a, ll b) {
    while (b) {
        a %=b;
        swap(a,b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a / gcd(a,b)) *b;
}

void solve() {
    ll b, q, y;
    cin >> b >> q >> y;
    
    ll c, r, z;
    cin >> c >> r >> z;

    ll b_last = b + (y -1) *q;
    ll c_last = c + (z- 1) *r;

    if (c < b || c_last > b_last || r % q != 0 || (c - b) % q != 0) {
        cout << 0 << endl;
        return;
    }

    if (c -r <b || c_last +r >b_last) {
        cout << -1 << endl;
        return;
    }

    ll ans = 0;
    for (ll i = 1; i *i <=r; i++) {
        if (r % i == 0) {
            ll p1 = i;
            if (lcm(p1, q) == r) {
                ll ways = (r / p1) % MOD;
                ans = (ans + (ways * ways) % MOD) % MOD;
            }
            
            ll p2 = r /i;
            if (p1 != p2 && lcm(p2, q) == r) {
                ll ways = (r / p2) % MOD;
                ans = (ans + (ways * ways) % MOD) % MOD;
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