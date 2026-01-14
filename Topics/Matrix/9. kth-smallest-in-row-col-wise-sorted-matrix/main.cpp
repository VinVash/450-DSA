#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector <vector<int>> &mat,int k)
{
    int n = mat.size();
        
    if(k == 0 || k > n*n || n == 0)
    return -1;
    
    if(k == 1)
    return mat[0][0];
    
    // define smallest and largest element in the matrix as
    // lower range & upper range
    int lo = mat[0][0];
    int hi = mat[n-1][n-1];
    
    // perform binary search (by value)
    // between smallest(top-left) and largest(bottom-down) values
    while (lo < hi) 
    {
        int mid = lo + (hi - lo) / 2;
        int count = 0;

        int j = n - 1;
        // find out how many numbers are greater than mid
        // between lo and hi
        for (int i = 0; i < n; i++) 
        {
            while (j >= 0 && mat[i][j] > mid) 
                j--;
                
            count += (j + 1);
        }
        
        // if the number of such elements is less than k,
        // narrow the search range by increasing lo value
        if (count < k) 
            lo = mid + 1;
        // if number of such element is greater or equal to k
        // narrow the search range by decreasing hi value
        else 
            hi = mid;
    } 
    
    // after iteratively narrowing the search range
    // you narrow down to a single element in the matrix
    // which is k-th smallest element
    return lo;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n, k;
    cin >> n >> k;
	
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}

	cout << kthSmallest(matrix, k) << endl;

	return 0;
}