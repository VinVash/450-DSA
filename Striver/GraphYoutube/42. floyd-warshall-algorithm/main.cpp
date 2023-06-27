#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: O(N^3)
// Space complexity: O(N^2)

void shortest_distance(vector<vector<int>>& matrix) {
	int n = matrix.size();

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(matrix[i][j] == -1)
				matrix[i][j] = 1e9;
			if(i == j)
				matrix[i][j] = 0;
		}
	}

	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}

	// Following loop is to check whether a negative cycle is there or not.
	for(int i = 0; i < n; i++) {
		if(matrix[i][i] < 0) {
			cout << "There is a negative cycle" << endl;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(matrix[i][j] == 1e9)
				matrix[i][j] = -1;
		}
	}	
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}