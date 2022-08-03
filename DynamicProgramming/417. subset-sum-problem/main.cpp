#include <bits/stdc++.h>
using namespace std;

int findPartition(vector<int> &arr, int n) {
	int sum = 0;
    int i, j;
    
    for(i = 0; i < n; i++)
        sum += arr[i];
        
    if(sum % 2 != 0)
        return 0;
        
    vector<bool> dp(sum / 2 + 1, false);
    
    for(i = 0; i < n; i++) {
        for(j = sum / 2; j >= arr[i]; j--) {
            if(dp[j - arr[i]] == true || j == arr[i])
                dp[j] = true;
        }
    }
    
    return dp[sum / 2];
}

int findPartition2(vector<int> &arr, int n) {
	int sum = 0;
	int i, j;

	for(i = 0; i < n; i++)
		sum += arr[i];

	if(sum % 2 != 0)
		return false;

	vector<vector<bool>> dp(sum/2+1, vector<bool>(n+1, false));

	for(i = 0; i <= n; i++)
		dp[0][i] = true;

	for(i = 1; i <= sum/2; i++)
		dp[i][0] = false;

	for(i = 1; i <= sum / 2; i++) {
		for(j = 1; j <= n; j++) {
			dp[i][j] = dp[i][j-1];
			if(i >= arr[j-1])
				dp[i][j] = dp[i][j] || dp[i - arr[j-1]][j-1];
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