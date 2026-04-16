#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    
    vector<int> p(n+1);
    for (int i = 1; i <=n; i++) cin >> p[i];

    vector<bool> vis(n+1, false);
    int cycles = 0;

    for (int i =1; i <=n; i++) {
        if (!vis[i]) {
            cycles++;
            int curr = i;
            while (!vis[curr]) {
                vis[curr] = true;
                curr = p[curr];
            }
        }
    }

    if ((n-cycles) %2 == (3LL*n) % 2) {
        cout << "Petr" << endl;
    } else {
        cout << "Um_nik" << endl;
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