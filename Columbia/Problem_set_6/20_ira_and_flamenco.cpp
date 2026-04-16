#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

// Modular exponentiation to calculate (base^exp) % MOD in O(log exp) time
// Source: Binary Exponentiation - CP-Algorithms
// Reference: https://cp-algorithms.com/algebra/binary-exp.html
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

void solve() {
    int n, m; 
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    
    vector<int> u;
    vector<ll> c;

    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i-1]) {
            u.push_back(a[i]);
            c.push_back(1);
        } else {
            c.back()++; // current element is the last element in c.
        }
    }

    int k = u.size();
    
    vector<ll> pref(k + 1, 1);
    for (int i = 0; i < k; i++) {
        pref[i+1] = (pref[i] * c[i]) % MOD;
    }

    ll ans = 0;
    for (int i = 0; i <= k-m; i++) {
        if (u[i+m-1] - u[i] == m-1) {
            ll ways = (pref[i+m] * modInverse(pref[i])) % MOD;
            ans = (ans + ways) % MOD;
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