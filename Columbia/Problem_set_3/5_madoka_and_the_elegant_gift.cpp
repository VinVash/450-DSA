#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> g(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
        g[i] = " " + g[i]; // 1-index cols
    }


    vector<vector<int>> col(n+1, vector<int>(m+1,0));
    vector<vector<int>> row(n+1, vector<int>(m+1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            row[i][j] = row[i][j-1] + (g[i][j]=='1');
            col[i][j] = col[i-1][j] + (g[i][j]=='1');
        }
    }
    auto rowAll = [&](int i,int l,int r)->bool{
        return row[i][r]-row[i][l-1] == r-l+1;
    };
    auto colAll = [&](int j,int a,int b)->bool{
        return col[b][j]-col[a-1][j] == b-a+1;
    };

    vector<vector<int>> diff(n+2, vector<int>(m+2,0));
    

    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            int j = 1;
            while (j <= m) {
                if (!colAll(j,a,b)) {
                    j++;
                    continue;
                }
                int l = j;
                while (j <= m && colAll(j,a,b)) j++;
                
                int r = j-1;

                bool up = (a > 1 && rowAll(a-1, l, r));
                bool down = (b < n && rowAll(b+1, l, r));
                if (!up && !down) {
                    diff[a][l] += 1;
                    diff[b+1][l] -= 1;
                    diff[a][r+1] -= 1;
                    diff[b+1][r+1] += 1;
                }
            }
        }
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            diff[i][j] += diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
            if (diff[i][j] > 1) flag = false;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
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