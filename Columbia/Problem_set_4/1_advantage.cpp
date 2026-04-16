#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    vector<int> s(n);
    int m1 = 0, m2 = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> s[i];

        if (s[i] > m1) {
            m2 = m1;
            m1 = s[i];
        } else if (s[i] > m2) {
            m2 = s[i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (s[i] == m1) cout << s[i] - m2 << " ";
        else cout << s[i] - m1 << " ";
    }
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