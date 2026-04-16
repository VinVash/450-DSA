#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<long long> p1(n + 1, 0); // left-to-right
    for (int i = 2; i <= n; i++) {
        p1[i] = p1[i-1] + max(0LL, a[i-1] - a[i]);
    }
    
    vector<long long> p2(n + 1, 0); // right-to-left
    for (int i = n - 1; i >= 1; i--) {
        p2[i] = p2[i+1] + max(0LL, a[i+1] - a[i]);
    }
    

    while (m--) {
        int s, t;
        cin >> s >> t;
        
        if (s < t) {
            cout << p1[t] - p1[s] << endl;
        } else {
            cout << p2[t] - p2[s] << endl;
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

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve();


    return 0;
}