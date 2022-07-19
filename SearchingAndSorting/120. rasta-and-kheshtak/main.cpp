#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &k1, vector<vector<int>> &k2, int n, int m, int x, int y) {
	
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;
	vector<vector<int>> k1(n, vector<int>(m, 0)); // khashtak 1.
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cin >> matrix[i][j];
	}

	int x, y;
	cin >> x >> y;
	vector<vector<int>> k2(x, vector<int>(y, 0)); // khashtak 2.
	
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++)
			cin >> matrix[i][j];
	}

	solve(k1, k2, n, m, x, y);

	return 0;
}