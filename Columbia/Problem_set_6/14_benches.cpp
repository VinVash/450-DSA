#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin >> n;

    long long cn5 = n * (n-1);
    cn5 *= (n - 2);
    cn5 *= (n - 3);
    cn5 *= (n - 4);
    cn5 /= 120;

    long long ans = cn5 * cn5 * 120;

    cout << ans << endl;
    
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