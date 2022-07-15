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

// second approach (n + m)
int rowWithMax1s2(vector<vector<int> > arr, int n, int m) {
	int j = m-1, max_row_index = 0;
 
    for (int i = 0; i < n; i++) {
        // Move left until a 0 is found
      bool flag = false; //to check whether a row has more 1's than previous
        while (j >= 0 && mat[i][j] == 1) {
            j = j - 1; // Update the index of leftmost 1
                       // seen so far
          	flag = true ;//present row has more 1's than previous
        }
      	// if the present row has more 1's than previous
      	if(flag){
            max_row_index = i; // Update max_row_index
        }
    }
      if(max_row_index == 0 && mat[0][C-1] == 0)
            return -1;
    return max_row_index;
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