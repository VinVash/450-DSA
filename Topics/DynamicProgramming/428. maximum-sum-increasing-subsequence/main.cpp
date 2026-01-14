#include <bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n) {
    vector<int> dp(n);
    
    for(int i = 0; i < n; i++)
        dp[i] = arr[i];
        
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && arr[i] + dp[j] > dp[i])
                dp[i] = dp[j] + arr[i];
        }
    }
    
    int max = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        if(dp[i] > max)
            max = dp[i];
    }
    
    return max;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}