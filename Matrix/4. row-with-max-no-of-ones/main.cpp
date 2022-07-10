#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    int i = 0, j = 0;
    int ans = -1;
    
    for(i = 0; i < m; i++) { // for cols.
        vector<int> temp;
        for(j = 0; j < n; j++) { // for rows.
            if(arr[j][i] == 1) temp.push_back(j);
        }
        if(temp.size()) {
        	ans = temp[0];
        	break;
        }
    }
    
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;

	vector<vector<int>> matrix(n, vector<int>(m, 0));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cin >> matrix[i][j];
	}

	cout << rowWithMax1s(matrix, n, m) << endl;	

	return 0;
}