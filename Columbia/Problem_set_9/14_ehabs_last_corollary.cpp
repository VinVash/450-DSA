#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k;
vector<vector<int>> adj;
vector<int> dep;
vector<int> par;
vector<int> vis;

void dfs(int u, int p, int d) {
    vis[u] = 1;
    dep[u] = d;
    par[u] = p;

    for (int i =0; i <adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p) continue;

        if (vis[v] ==1) {
            if (dep[u] -dep[v] +1 <=k) {
                cout << 2 << endl;
                int len = dep[u] -dep[v] +1;
                cout << len << endl;
                int curr =u;
                while (curr !=v) {
                    cout << curr << " ";
                    curr = par[curr];
                }
                cout << v << endl;
                exit(0);
            }
        } else if (vis[v] == 0) {
            dfs(v, u, d+1);
        }
    }
    vis[u] = 2;
}

void solve() {
    cin >> n >> m >> k;
    
    adj.resize(n+1);
    dep.resize(n+1);
    par.resize(n+1);
    vis.resize(n+1, 0);

    for (int i =0; i <m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 1);

    vector<pair<int, int>> order;
    for (int i =1; i <=n; i++) {
        order.push_back({dep[i],i});
    }
    sort(order.rbegin(), order.rend());

    vector<int> ans;
    vector<bool> mark(n+1, false);
    int tar = (k+1) /2;

    for (int i = 0; i <n; i++) {
        int u = order[i].second;
        if (!mark[u]) {
            ans.push_back(u);
            mark[u] = true;
            for (int j = 0; j < adj[u].size(); j++) {
                mark[adj[u][j]] = true;
            }
            if (ans.size() == tar) {
                break;
            }
        }
    }

    cout << 1 << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
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

    solve();

    return 0;
}