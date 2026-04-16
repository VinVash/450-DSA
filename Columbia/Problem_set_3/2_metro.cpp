#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n, s; cin >> n >> s;
	vector<int> a(n+1), b(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];

	if (!a[1]) {
        cout << "NO";
        return;
    }

    if (a[s]) {
        cout << "YES";
        return;
    }

    for (int i = s + 1; i <= n; i++) {
        if (a[i] && b[i] && b[s]) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";


}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int t; cin >> t;
    // while(t--) {
    // 	solve();
    // }

    solve();

    return 0;
}