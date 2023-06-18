#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: O(N x M)
// Space complexity: O(N x M)
int numberOfEnclaves(vector<vector<int>> &grid) {
	queue<pair<int, int>> q; // stores the points (r, c)
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> vis(n, vector<int>(m, 0));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(i == 0 || i == n-1 || j == 0 || j == m-1) {
				if(grid[i][j] == 1) {
					q.push({i, j});
					vis[i][j] = 1;
				}
			}
		}
	}

	int delrow[] = {-1, 0, 1, 0};
	int delcol[] = {0, 1, 0, -1};

	while(!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		// traverse all 4 directions
		for(int i = 0; i < 4; i++) {
			int nrow = row + delrow[i];
			int ncol = col + delcol[i];

			if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
				q.push({nrow, ncol});
				vis[nrow][ncol] = 1;
			}
		}
	}

	int res = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == 1 && vis[i][j] == 0)
				res++;
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