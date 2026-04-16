#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    if (a[0] == 1) {
        cout << n+1 << " ";
        for (int i= 1; i <=n;i++) cout << i << " ";
        cout << endl;
        return;
    }
    
    if (a[n-1] == 0) {
        for (int i =1; i <=n;i++) cout << i << " ";
        cout << n+1 << endl;
        return;
    }
    
    int pos = -1;
    for (int i =0; i < n-1; i++) {
        if (a[i] == 0 && a[i+1] == 1) {
            pos =i;
            break;
        }
    }
    
    for (int i =1; i <= pos+1; i++) cout << i << " ";
    cout << n+1 << " ";
    for (int i = pos+2; i <=n; i++) cout << i << " ";
    cout << endl;
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