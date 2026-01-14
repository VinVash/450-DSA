#include <bits/stdc++.h>
using namespace std;

void printCommonElements(vector<vector<int>> &mat, int m, int n) {
    unordered_map<int, int> mp;
 
    // add first row elements in the map.
    for (int j = 0; j < n; j++)
        mp[mat[0][j]] = 1;
 
    // traverse the matrix
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // If element is present in the map and
            // is not duplicated in current row.
            if (mp[mat[i][j]] == i)
            {
               // we increment count of the element in map by 1
                mp[mat[i][j]] = i + 1;
 
                // If this is last row
                if (i == m-1 && mp[mat[i][j]] == m)
                  cout << mat[i][j] << " ";
            }
        }
    }
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int m, n;
	cin >> m >> n;
	
	vector<vector<int>> matrix(m, vector<int>(n, 0));
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}

	printCommonElements(matrix, m, n);

	return 0;
}