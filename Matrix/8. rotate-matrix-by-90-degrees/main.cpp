#include <bits/stdc++.h>
using namespace std;

void rotate90(vector<vector<int>> &m, int n) {
	for(int i = 0; i < n/2; i++) {
		for(int j = i; j < n-i-1; j++) {
			int temp = m[i][j];
			m[i][j] = m[n-1-j][i];
			m[n-1-j][i] = m[n-1-i][n-1-j];
			m[n - 1 - i][n - 1 - j] = m[j][n - 1 - i];
            m[j][n - 1 - i] = temp;
		}
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;
	
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}

	rotate90(matrix, n);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}


	return 0;
}