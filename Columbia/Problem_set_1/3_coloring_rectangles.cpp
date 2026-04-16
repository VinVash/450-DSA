#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n, m; cin >> n >> m;

	cout << (n * m + 2) / 3 << endl;

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