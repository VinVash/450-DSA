#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;
    
    vector<int> count(101, 0); 
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        count[a]++;
    }
    
    int total = 0;
    for (int i = 1; i <= 100; i++) {
        if (count[i] > 0) {
            total += min(count[i], c);
        }
    }
    
    cout << total << "\n";
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