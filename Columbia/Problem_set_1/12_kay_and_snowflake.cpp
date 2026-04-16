#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
vector<int> adj[MAXN];
int sz[MAXN], parent[MAXN], ans[MAXN];

void dfs(int u) {
	sz[u] = 1;
	int heavy_child = -1;

	for(int v: adj[u]) {
		dfs(v);

		sz[u] += sz[v];

		if(heavy_child == -1 || sz[v] > sz[heavy_child]) {
			heavy_child = v;
		}
	}

	if(heavy_child == -1) { // leaf node
		ans[u] = u;
	} else {
		int curr = ans[heavy_child];

		while((sz[u] - sz[curr]) > sz[u] / 2) {
			curr = parent[curr];
		}
		ans[u] = curr;
	}
}

void solve() {
	int n, q; cin >> n >> q;

	for(int i = 2; i <= n; i++) {
		int p; cin >> p;
		adj[p].push_back(i);
		parent[i] = p;
	}
	dfs(1);

	while(q--) {
		int v; cin >> v;
		cout << ans[v] << endl;
	}

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
