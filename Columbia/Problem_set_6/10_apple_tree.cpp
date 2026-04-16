#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<long long> leafc;

void count(int u, int parent) {
    bool isleaf = true;
    leafc[u] = 0;

    for(int v: adj[u]) {
        if(v != parent) {
            isleaf = false;
            count(v, u);
            leafc[u] += leafc[v];
        }
    }

    if(isleaf) leafc[u] = 1;
}

void solve() {
    int n; cin >> n;

    adj.assign(n+1, vector<int>());
    leafc.assign(n+1, 0);

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    count(1, -1);

    int q; cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;

        long long ans = leafc[x] * leafc[y];

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

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    // solve();

	return 0;

}