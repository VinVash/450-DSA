#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis,int i, int j, set<pair<int, int>>& st) {

    vis[i][j] = 1;
    st.insert({i, j});

    int n = grid.size(), m = grid[0].size();

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for(int k = 0; k < 4; k++) {

        int ni = i + dx[k];
        int nj = j + dy[k];

        if(isValid(ni, nj, n, m) && !vis[ni][nj] && grid[ni][nj] == 1)
            dfs(grid, vis, ni, nj, st);
    }
}

int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    set<pair<int, int>> s1, s2;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int f = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 && !vis[i][j]) {
                if(f == 0) {
                    dfs(grid, vis, i, j, s1);
                    f++;
                } else {
                    dfs(grid, vis, i, j, s2);
                }
            }
        }
    }

    int ans = INT_MAX;

    for(auto i: s1) {
        for(auto j: s2) {
            ans = min(ans, abs(i.first - j.first) + abs(i.second - j.second) - 1);
        }
    }

    return ans;

}


int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;

	vvi grid(n, vi(m, 0));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	int ans = shortestBridge(grid);

	cout << "Ans: " << ans << endl;


	return 0;
}