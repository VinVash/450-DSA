#include <bits/stdc++.h>
using namespace std;

void sortedMatrix(vector<vector<int>> &matrix, int r, int c) {
	vector<int> temp;

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			temp.push_back(matrix[i][j]);
		}
	}

	sort(temp.begin(), temp.end());

	for(int i = 0; i < r*c; i++)
		cout << temp[i] << " ";
	cout << endl;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int r, c;

	cin >> r >> c;

	vector<vector<int>> matrix(r, vector<int>(c, 0));

	for(int i = 0; i < r; i++ ) {
		for(int j = 0; j < c; j++)
			cin >> matrix[i][j];
	}

	sortedMatrix(matrix, r, c);


	return 0;
}