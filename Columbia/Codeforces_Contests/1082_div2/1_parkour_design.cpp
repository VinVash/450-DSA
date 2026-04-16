#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x, y;
    cin >> x >> y;

    long long diff = x - 2 * y;

    if (diff >= 0 && diff % 3 == 0 && x >= -4 * y) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
    	solve();
    }

    // solve();

    return 0;
}