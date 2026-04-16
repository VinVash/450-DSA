#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    cout << 2 << endl;
    
    int prev = n;
    for (int i = n - 1; i >= 1; i--) {
        cout << i << " " << prev << endl;
        prev = (i + prev + 1) / 2;
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