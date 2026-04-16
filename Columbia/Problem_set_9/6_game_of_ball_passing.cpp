#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    
    ll sum = 0;
    ll maxi = 0;
    
    for (int i =0; i <n; i++) {
        ll v; cin >> v;
        sum += v;
        maxi = max(maxi, v);
    }
    
    if (sum == 0) {
        cout << 0 << endl;
    } else if (2*maxi >sum) {
        cout << 2*maxi -sum << endl;
    } else {
        cout << 1 << endl;
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