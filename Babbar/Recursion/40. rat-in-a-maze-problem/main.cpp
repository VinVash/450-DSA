#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m) {
	if(x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1) {
		return true;
	} else {
		return false;
	}
}
    
void solve(vector<vector<int>> m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path) {
	// you have reaced x,y here.

	// base case.
	if(x == n-1 && y == n-1) {
		ans.push_back(path);
		return;
	}

	visited[x][y] = 1;
	// 4 choices -> D, L, R, U.

	// D
	int newx = x+1;
	int newy = y;
	if(isSafe(newx, newy, n, visited, m)) {
		path.push_back('D');
		solve(m, n, ans, newx, newy, visited, path);
		path.pop_back(); // jo 'D' humne daala hai, use hatana hai.
	}

	// L
	 newx = x;
	 newy = y-1;
	if(isSafe(newx, newy, n, visited, m)) {
		path.push_back('L');
		solve(m, n, ans, newx, newy, visited, path);
		path.pop_back(); // jo 'D' humne daala hai, use hatana hai.
	}

	// R
	 newx = x;
	 newy = y+1;
	if(isSafe(newx, newy, n, visited, m)) {
		path.push_back('R');
		solve(m, n, ans, newx, newy, visited, path);
		path.pop_back(); // jo 'D' humne daala hai, use hatana hai.
	}

	// U
	 newx = x-1;
	 newy = y;
	if(isSafe(newx, newy, n, visited, m)) {
		path.push_back('U');
		solve(m, n, ans, newx, newy, visited, path);
		path.pop_back(); // jo 'D' humne daala hai, use hatana hai.
	}

	visited[x][y] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;

	if(m[0][0] == 0)
		return ans;

	int srcx = 0;
	int srcy = 0;

	vector<vector<int>>visited(n, vector<int>(n, 0));
	string path = "";

	solve(m, n, ans, srcx, srcy, visited, path);
	sort(ans.begin(), ans.end());
	return ans;
}


int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}