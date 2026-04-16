#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    
    vector<int> x(n);
    for (int i =0; i <n;i++) cin >> x[i];
    
    vector<int> y(n);
    for (int i =0; i <n;i++) cin >> y[i];
    
    int a = -2e9;
    int b = -2e9;
    
    for (int i = 0; i <n; i++) {
        a = max(a, x[i] + y[i]);
        b = max(b, y[i] - x[i]);
    }
    
    cout << fixed << setprecision(6) << (a-b) /2.0 << endl;
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