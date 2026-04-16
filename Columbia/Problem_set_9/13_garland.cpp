#include <bits/stdc++.h>
using namespace std;

int n, r;
long long tot = 0, tar;
vector<vector<int>> adj;
vector<int> t, ans;

long long dfs(int u) {
    long long s = t[u];
    for (int i = 0; i < adj[u].size(); i++) {
        s += dfs(adj[u][i]);
    }
    if (u != r && s == tar) {
        ans.push_back(u);
        return 0;
    }
    return s;
}

void solve() {
    cin >> n;
    adj.resize(n+1);
    t.resize(n+1);

    for (int i =1; i <=n; i++) {
        int p; cin >> p >> t[i];
        tot +=t[i];
        if (p ==0) {
            r =i;
        } else {
            adj[p].push_back(i);
        }
    }

    if (tot %3 !=0) {
        cout << -1 << endl;
        return;
    }

    tar = tot /3;
    dfs(r);

    if (ans.size() >=2) {
        cout << ans[0] << " " << ans[1] << endl;
    } else {
        cout << -1 << endl;
    }
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