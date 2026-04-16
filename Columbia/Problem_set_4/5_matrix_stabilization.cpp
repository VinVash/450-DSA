#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
    cin >> n >> m;
    
    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long long maxi = 0;
            
            for (int d = 0; d < 4; d++) {
                int nr = i + dx[d];
                int nc = j + dy[d];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    maxi = max(maxi, a[nr][nc]);
                }
            }
            
            if (a[i][j] > maxi) {
                a[i][j] = maxi;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << (j == m - 1 ? "" : " ");
        }
        cout << endl;
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
    return 0;
}