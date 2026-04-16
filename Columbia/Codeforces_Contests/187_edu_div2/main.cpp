#include <bits/stdc++.h>
using namespace std;

void solve() {

    long long n, m, d;
    cin >> n >> m >> d;

    long long max_per_tower = (d/m) + 1;

    long long ans = (n + max_per_tower - 1) / max_per_tower;

    cout << ans << endl;
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

    return 0;
}