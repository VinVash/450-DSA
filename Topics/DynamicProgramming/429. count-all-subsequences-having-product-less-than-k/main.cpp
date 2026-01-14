#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &arr, int currProd, int index, int k) {
	cout << currProd << " " << index << endl;

	if(currProd > k) {
		return 0;
	}

	if(index < 0) {
		return 0;
	}

	int a = 1 + solveRec(arr, currProd * arr[index], index-1, k);
	int b = 1 + solveRec(arr, currProd, index-1, k);

	return a + b;
}

// dp[i][j] = number of subsequences having product less than i using first j terms of the array.
int productSubSeqCount(vector<int> &arr, int k) {
    int n = arr.size();

    // dp array initialise
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));

	// for loop dp array filling.
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
    
            // number of subsequence using j-1 terms
            dp[i][j] = dp[i][j - 1];
   
            // if arr[j-1] > i it will surely make product greater
            // thus it won't contribute then
            if (arr[j - 1] <= i)
 
                // number of subsequence using 1 to j-1 terms
                // and j-th term
                dp[i][j] += dp[i / arr[j-1]][j-1] + 1;
        }
    }
    return dp[k][n];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> arr {1, 2, 3, 4};
	int n = arr.size();
	int k = 10;

	cout << solveRec(arr, 1, n-1, k) << endl;

	return 0;
}