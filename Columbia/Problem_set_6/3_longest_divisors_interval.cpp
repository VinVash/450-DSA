#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin >> n;

    int ans = 0;
    long long i = 1;
    while(n % i == 0) {
        i++;
    }
    cout << i-1 << endl;

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