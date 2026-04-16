#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    
    vector<int> A(n);
    for (int i = 0; i <n; i++) cin >> A[i];

    vector<int> B(n);
    for (int i = 0; i <n; i++) cin >> B[i];
    
    int m; cin >> m;
    
    vector<int> C(m);
    for (int i = 0; i <m; i++) cin >> C[i];
    
    vector<int> D(m);
    for (int i = 0; i <m; i++) cin >> D[i];
    
    ll ans = 1;
    ll MOD = 998244353;
    
    int i = 0, j = 0;
    while (i < n || j < m) {
        if (i < n && j < m && A[i] ==C[j]) {
            if (B[i] < D[j]) {
                ans = 0;
            } else if (B[i] > D[j]) {
                ans = (ans * 2) % MOD;
            }
            i++; j++;
        } else if (j == m || (i < n && A[i] < C[j])) {
            if (B[i] > 0) {
                ans = (ans * 2) % MOD;
            }
            i++;
        } else if (i == n || (j < m && A[i] > C[j])) {
            ans = 0;
            j++;
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