#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n; cin >>  n;
    vector<int> p(n+1);
    for(int i = 1; i <= n; i++) cin >> p[i];

    string s; cin >> s;

    vector<int> ans(n+1, 0), vis(n+1, 0);

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;

        vector<int> cycle;
        int curr = i;

        while(!vis[curr]) {
            vis[curr] = 1;
            cycle.push_back(curr);
            curr = p[curr];
        }

        int black = 0;
        for(int x: cycle) {
            if(s[x-1] == '0') black++;
        }

        for(int x: cycle) ans[x] = black;
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

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