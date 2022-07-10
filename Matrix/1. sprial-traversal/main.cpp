#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > &matrix, int r, int c) {
    vector<int> traversal;
    int r1 = 0, r2 = r;
    int c1 = 0, c2 = c;
    
    while(r1 < r2 && c1 < c2) {

    	for(int i = c1; i < c2; i++) {
    		traversal.push_back(matrix[r1][i]);
    	}
    	r1++;

		for(int i = r1; i < r2; i++) {
    		traversal.push_back(matrix[i][c2-1]);
    	}
    	c2--;

    	if(r1 < r2) {
    		for(int i = c2-1; i >= c1; i--) {
	    		traversal.push_back(matrix[r2-1][i]);
	    	}
	    	r2--;
    	}

    	if(c1 < c2) {
    		for(int i = r2-1; i>= r1; i--) {
	    		traversal.push_back(matrix[i][c1]);
	    	}
	    	c1++;
    	}
    }

    return traversal;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int r, c;
    cin >> r >> c;

    vector<vector<int> > matrix;

    for(int i = 0; i < r; i++) {
    	vector<int> temp;
    	for(int j = 0; j < c; j++) {
    		int x; cin >> x;
    		temp.push_back(x);
    	}
    	matrix.push_back(temp);
    }

    vector<int> res = spirallyTraverse(matrix, r, c);

    for(int i = 0; i < res.size(); i++)
    	cout << res[i] << " ";
    cout << endl;


	return 0;
}