#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    
    vector<long long> a(n);
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    
    if ((2 * total) % n != 0) {
        cout << 0 << endl;
        return;
    }
    
    long long target = (2 * total) / n;
    map<long long, int> freq;
    long long valid = 0;
    
    for (int i = 0; i < n; i++) {
        valid += freq[target - a[i]];
        
        freq[a[i]]++;
    }
    
    cout << valid << endl;
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