#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n, m;
    cin >> n >> m;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
        
    vector<long long> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    long long curr = 0;
    
    for (int i = 0; i < n; i++) {
        curr += abs(a[i] - b[m - 1 - i]);
    }
    
    long long max_sum = curr;
    
    for (int k = 0; k < n; k++) {
        curr -= abs(a[n - 1 - k] - b[m - n + k]);
        curr += abs(a[n - 1 - k] - b[k]);
        
        max_sum = max(max_sum, curr);
    }
    
    cout << max_sum << endl;
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