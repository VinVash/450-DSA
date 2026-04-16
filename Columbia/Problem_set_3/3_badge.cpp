#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;

	vector<int> p(n+1);

    for (int i = 1; i <= n; i++) cin >> p[i];

    for (int a = 1; a <= n; a++) {
        vector<int> vis(n + 1, 0);
        int cur = a;

        while (!vis[cur]) {
            vis[cur] = 1;
            cur = p[cur];
        }

        cout << cur << " ";
    }
    cout << endl;

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