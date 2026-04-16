#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 200005;
vector<pair<int, pair<ll, ll>>> adj[MAX];
int ans[MAX];
vector<ll> bp;

void dfs(int u, ll sum) {
    if (u != 1) {
        ans[u] = upper_bound(bp.begin(), bp.end(), sum) -bp.begin() -1;
    }
    for (int i =0; i <adj[u].size(); i++) {
        int v = adj[u][i].first;
        ll a = adj[u][i].second.first;
        ll b = adj[u][i].second.second;
        
        bp.push_back(bp.back()+b);
        dfs(v, sum+a);
        bp.pop_back();
    }
}

void solve() {
    int n; cin >> n;
    
    for (int i =1; i <=n; i++) {
        adj[i].clear();
    }
    
    for (int i =2; i <=n; i++) {
        int p; ll a, b;
        cin >> p >> a >> b;
        adj[p].push_back({i, {a, b}});
    }
    
    bp.clear();
    bp.push_back(0);
    
    dfs(1, 0);
    
    for (int i =2; i <=n; i++) {
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

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}