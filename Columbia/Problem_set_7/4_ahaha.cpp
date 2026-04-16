#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int z = 0;
    int o = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0) z++;
        else o++;
    }
    
    if (z >= n / 2) {
        cout << n / 2 << endl;
        for (int i = 0; i < n / 2; i++) {
            cout << 0 << " ";
        }
        cout << endl;
    } else {
        int k = n / 2;
        if (k % 2 != 0) {
            k++;
        }
        cout << k << endl;
        for (int i = 0; i < k; i++) {
            cout << 1 << " ";
        }
        cout << endl;
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