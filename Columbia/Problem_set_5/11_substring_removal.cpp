#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    long long l1 = 1;
    while (l1 < n && s[l1] == s[0]) {
        l1++;
    }
    
    long long l2 = 1;
    while (l2 < n && s[n-1 -l2] == s[n-1]) {
        l2++;
    }
    
    long long MOD = 998244353;
    if (s[0] == s[n-1]) {
        long long ans = ((l1+1) * (l2+1)) % MOD;
        cout << ans << endl;
    } else {
        long long ans = (l1+l2 + 1) % MOD;
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