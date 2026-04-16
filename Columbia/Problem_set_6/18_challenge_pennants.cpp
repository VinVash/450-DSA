#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll comb(ll n, ll r) {
    if (r<0 || r>n) return 0;
    if (r==0 || r==n) return 1;
    if (r>n /2) r = n - r;
    
    ll ans = 1;
    for (int i = 1; i <=r; i++) {
        ans = ans * (n- i+1) / i;
    }
    return ans;
}

void solve() {
    
    ll n; cin >> n;

    ll bugs = comb(n + 4, 5);
    ll features = comb(n + 2, 3);

    cout << bugs*features << endl;
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