#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u][v] = 1;
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int t; cin >> t;
        if(t == 1) {
            int u, v; cin >> u >> v;
            adj[u][v] = 1;
        } else if(t == 2) {
            int u, v; cin >> u >> v;
            adj[u][v] = 0;
        } else {
            // t == 3 -> battle
            for(int node = 1; node <= n; node++) {
                for(int neigh = 1; neigh <= n; neigh++) {
                    if(adj[node][neigh] == -1) adj[node][neigh] = 0;
                }
            }
            bool flag = true;
            while(flag) {

                bool changed = false;
                for(int curr = 1; curr <= n; curr++) {
                    bool safe = true;
                    for(int j = 1; j <= curr-1; j++) {
                        if(adj[curr][j] == 1) {
                            safe = false;
                            changed = true;
                        }
                    }
                    if(!safe) {
                        for(int j = 1; j <= n; j++) adj[curr][j] = -1;
                    }
                }

                if(!changed) {
                    flag = false;
                }
            }
            int ans = 0;
            for(int node = 1; node <= n; node++) {
                if(adj[node][0] != -1) ans++;
            }
            cout << ans << endl;


        }
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