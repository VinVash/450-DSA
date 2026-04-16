#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

void solve() {
	long long n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    long long ans = (n *(n -1)) % MOD; // n(n-1)
    
    for (long long i = 1; i <=n; i++) { // multiply with n!
        ans = (ans*i) %MOD;
    }

    cout << ans << endl;
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