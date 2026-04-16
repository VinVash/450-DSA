#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> c(x+1, 0);
    for (int i =0; i <n; i++) {
        int a; cin >> a;
        c[a]++;
    }
    for (int i =1; i <x; i++) {
        if (c[i]% (i +1) != 0) {
            cout << "No" << endl;
            return;
        }
        c[i+1] += c[i] / (i+1);
    }
    cout << "Yes" << endl;
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