#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    
    int k = 0;
    ll s = 0;
    for (int i = 0; i < n; i++) {
        if (s + b[i] <= m) {
            s += b[i];
            k++;
        } else {
            break;
        }
    }
    
    if (k == 0) { // beat nobody
        cout << n+1 << endl;
    } else if (k ==n) { // beat everybody
        cout << 1 << endl;
    } else {
        if (s - b[k-1] + a[k] <= m) { // you beat kth player
            cout << n-k << endl;
        } else {
            cout << n-k + 1 << endl; // you lose to k - rank decreases
        }
    }
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