#include <bits/stdc++.h>
using namespace std;

// Space complexity: O(N^2) - visited matrix + O(N^2) - if all the elements are 1 (queue space)
// Time complexity: O(8 * N^2) ~ O(N^2)
void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> grid) {
	vis[r][c] = 1;
	queue<pair<int, int>> q;
	q.push({ r, c });
	int n = grid.size();
	int m = grid[0].size();

	while(q.size()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for(int delrow = -1; delrow <= 1; delrow++) {
			for(int delcol = -1; delcol <=1 ; delcol++) {
				int currrow = row + delrow;
				int currcol = col + delcol;

				if(currrow >= 0 && currrow < n && currcol >= 0 && currcol < m && grid[currrow][currcol] == '1' && vis[currrow][currcol] == 0) {
					vis[currrow][currcol] = 1;
					q.push({ currrow, currcol });
				}
			}
		}
	}
}

int numIslands(vector<vector<char>> &grid) {
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> vis(n, vector<int>(m, 0));
	int res = 0;

	for(int r = 0; r < n; r++) {
		for(int c = 0; c < m; c++) {
			if(!vis[r][c] && grid[r][c] == '1') {
				res++;
				bfs(r, c, vis, grid);
			}
		}
	}

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}