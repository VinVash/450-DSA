#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> mat) {
	vis[row][col] = 1;
	int n = mat.size();
	int m = mat[0].size();

	int delrow[] = {-1, 0, 1, 0};
	int delcol[] = {0, 1, 0, -1};


	for(int i = 0; i < 4; i++) {
		int nrow = row + delrow[i];
		int ncol = col + delcol[i];

		if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
			dfs(nrow, ncol, vis, mat);
		}
	}
}

// Time complexity: O(N x M) + O(N) = O(N x M)
// Space complexity: O(N x M)
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
	
	vector<vector<int>> vis(n, vector<int>(m, 0));

	/* Visit all the O's which are visitable by the boundaries, therefore only those O's will be left which are inside X's  */

	for(int j = 0; j < m; j++) {
		if(!vis[0][j] && mat[0][j] == 'O') {
			dfs(0, j, vis, mat);
		}

		if(!vis[n-1][j] && mat[n-1][j] == 'O') {
			dfs(n-1, j, vis, mat);	
		}
	}

	for(int i = 0; i < n; i++) {
		if(!vis[i][0] && mat[i][0] == 'O') {
			dfs(i, 0, vis, mat);
		}

		if(!vis[i][m-1] && mat[i][m-1] == 'O') {
			dfs(i, m-1, vis, mat);
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!vis[i][j] && mat[i][j] == 'O') {
				mat[i][j] = 'X';
			}
		}
	}

	return mat;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}