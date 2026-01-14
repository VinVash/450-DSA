#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: O(N x M) + O(N x M) * 4 = O(N x M)
// Space complexity: O(N x M)
vector<vector<int>> nearest(vector<vector<int>> grid) {
	int n = grid.size();
	int m = grid[0].size();

	vector<vector<int>> vis(n, vector<int>(m, 0));
	vector<vector<int>> dist(n, vector<int>(m, 0));

	queue<pair<pair<int, int>, int>> q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == 1) {
				q.push({{i,j}, 0});
				vis[i][j] = 1;
			}
		}
	}

	int delrow[] = {-1, 0, 1, 0};
	int delcol[] = {0, 1, 0, -1};

	while(!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		int steps = q.front().second;
		q.pop();

		dist[row][col] = steps; // mark the dist of (row, col) as steps.

		for(int i = 0; i < 4; i++) {
			int nrow = row + delrow[i];
			int ncol = col + delcol[i];

			if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
				vis[nrow][ncol] = 1;
				q.push({{nrow, ncol}, steps+1});
			}
		}
	}

	return dist;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}