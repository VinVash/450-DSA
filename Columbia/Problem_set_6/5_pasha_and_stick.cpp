#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n; cin >> n;

	if (n % 2 != 0) {
        cout << 0 << endl;
    } else {
        long long temp = n/2;
        
        long long ans = (temp-1) /2;
        
        cout << ans << endl;
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