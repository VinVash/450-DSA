#include <bits/stdc++.h>
using namespace std;

void solve() {	
	int n, q;
    cin >> n >> q;
    
    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    
    while (q--) {
        long long l, r, k;
        cin >> l >> r >> k;
        
        long long org = pre[r] - pre[l - 1];
        long long newr = (r - l + 1) * k;
        
        long long newt = pre[n] - org + newr;
        
        if (newt % 2 != 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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