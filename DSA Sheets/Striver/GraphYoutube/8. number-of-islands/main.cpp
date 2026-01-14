#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Space complexity: O(N^2)

// Time complexity: O(N^2)

void eraseIsland(vector<vector<char>>& grid, int i, int j) {
    if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == '1') {
        grid[i][j] = '0';
        eraseIsland(grid, i+1, j);
        eraseIsland(grid, i-1, j);
        eraseIsland(grid, i, j+1);
        eraseIsland(grid, i, j-1);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();

    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1') {
                ans++;
                eraseIsland(grid, i, j);
            }
        }
    }

    return ans;
}


void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& vis, ) {
	vis[i][j] = 1;
	queue<pair<int, int>> q;
	q.push({ i, j });

	int m = grid.size(), n = grid[0].size();

	while(!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		// traverse the neigbours and mark them if its a land.
		for(int delrow = -1; delrow <= 1; delrow++) {
			for(int delcol = -1; delcol <= 1; delcol++) {
				int nrow = row + delrow; // neighbour row.
				int neighbourCol = col + delcol; // neighbour col

				if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
					vis[nrow][ncol] = 1;
					q.push({ nrow, ncol });
				}
			}
		}
	}
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> vis(m, vector<int>(n, 0));

    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j] && grid[i][j] == '1') {
                ans++;
                bfs(grid, i, j, vis);
            }
        }
    }

    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}