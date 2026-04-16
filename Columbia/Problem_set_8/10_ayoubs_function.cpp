#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    
    ll total = n *(n+1) /2;
    ll z = n -m;
    ll g = m +1;
    
    ll k = z /g;
    ll rem = z %g;
    
    ll sub = rem *(k+1) *(k+2) /2 + (g -rem) *k *(k+1) /2;
    ll ans = total - sub;
    
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