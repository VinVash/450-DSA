#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    
    vector<ll> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<ll> pa(n+1, 0);
    for (int i = 0; i <n; i++) {
        pa[i+1] = pa[i] + a[i];
    }
    
    vector<ll> pb(m+1, 0);
    for (int i = 0; i <m; i++) {
        pb[i+1] = pb[i] + b[i];
    }
    
    int kmax = min({n, m, (n+m)/3});
    cout << kmax << endl;
    
    for (int k = 1; k <= kmax; k++) {
        int mini = max(0, 2*k -m);
        int maxi = min(k, n-k);
        
        int low = mini;
        int high = maxi-1;
        int opt = mini;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            ll s1a = pa[n] - pa[n-mid] -pa[mid];
            ll s1b = pb[m] - pb[m -(k-mid)] - pb[k-mid];
            ll s1 = s1a + s1b;
            
            ll s2a = pa[n] - pa[n -(mid+1)] - pa[mid+1];
            ll s2b = pb[m] - pb[m -(k - (mid+1))] - pb[k -(mid+1)];
            ll s2 = s2a + s2b;
            
            if (s2 >= s1) {
                opt = mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        ll sa = pa[n] - pa[n - opt] - pa[opt];
        ll sb = pb[m] - pb[m - (k - opt)] - pb[k - opt];
        ll ans = sa + sb;
        
        cout << ans << (k == kmax ? "" : " ");
    }
    if (kmax > 0) cout << endl;
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