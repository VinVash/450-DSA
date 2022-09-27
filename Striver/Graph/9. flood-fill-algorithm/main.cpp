#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int delRow[], int delCol[], int iniColor) {
	ans[r][c] = newColor;
	int n = image.size();
	int m = image[0].size();
	for(int i = 0; i < 4; i++) {
		int nrow = r + delRow[i];
		int ncol = c + delCol[i];

		if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
			dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
		}
	}
}

// Space complexity: O(N x M) -> ans matrix + O(N x M) -> recursion stack space
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
	int iniColor = image[sr][sc];
	vector<vector<int>> ans = image;

	int delRow[] = {-1, 0, 1, 0};
	int delCol[] = {0, 1, 0, -1};
	dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);

	return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}