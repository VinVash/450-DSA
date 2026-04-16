#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    long long total = 0;

    for (int i = 0; i < n; i++) {
        int w= 0, b =0;
        for (int j = 0; j < m; ++j) {
            if (grid[i][j]== 0) w++;
            else b++;
        }
        total +=(1LL<< w) -1; // 2^w - 1
        total +=(1LL<< b)- 1; // 2^b - 1
    }

    for (int j = 0; j < m; ++j) {
        int w= 0, b =0;
        for (int i = 0; i < n; ++i) {
            if (grid[i][j]== 0) w++;
            else b++;
        }
        total +=(1LL<< w) -1; // 2^w - 1
        total +=(1LL<< b)- 1; // 2^b - 1
    }

    total -= n*m;

    cout << total << endl;
    
}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve();

	return 0;

}