#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
    	cin >> grid[i];
    }

    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g[i][j] = grid[i][j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 1) {
                bool rowOk = true;
                for (int k = 0; k < j; k++) {
                    if (g[i][k] == 0) {
                        rowOk = false;
                        break;
                    }
                }
                
                bool colOk = true;
                for (int k = 0; k < i; k++) {
                    if (g[k][j] == 0) {
                        colOk = false;
                        break;
                    }
                }
                
                if (!rowOk && !colOk) { // both need to be false
                	cout << "NO" << endl;
                	return;
                }
            }
        }
    }
    
    cout << "YES" << endl;

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

    return 0;
}