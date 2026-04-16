#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n, k; cin >> n >> k;

	if(k >= n-1) {
		cout << 1 << endl;
	} else {
		cout << n << endl;
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