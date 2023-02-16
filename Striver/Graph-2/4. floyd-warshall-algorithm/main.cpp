#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(N^3)
// Space complexity: O(N^2) // because we are using the matrix.
void shortest_distance(vector<vector<int>>&matrix){
	    
    // set the -1 elements to INT_MAX and diagonal elements as 0.
    int n = matrix.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == -1)
                matrix[i][j] = INT_MAX;
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
    
    
   // To check for negative cycle
   //for(int i = 0; i < n; i++) {
   //    if(matrix[i][i] < 0 ) {
   //         cout << "Negative cycle found!" << endl;
   //         break;
   //    }
   //}
   
    
    // set the INT_MAX elements to -1 while returning.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == INT_MAX)
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