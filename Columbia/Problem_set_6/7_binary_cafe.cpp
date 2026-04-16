#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    if (k >= 30) {
        cout << n+1 << endl;
    } else {
        long long maxi = 1 << k;
        cout << min(n+1, maxi) << endl;
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

    // solve();

	return 0;

}