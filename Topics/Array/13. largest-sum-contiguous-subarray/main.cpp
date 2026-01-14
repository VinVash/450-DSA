#include <bits/stdc++.h>
using namespace std;

// Kadane's Algorithm
long long maxSubarraySum(vector<int> &arr, int n){

    int curr = 0, maxsum = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        if(curr < 0) curr = 0;
        curr += arr[i];
        maxsum = max(maxsum, curr);
    }
    return maxsum;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> arr {1, 2, 3, -2, 5};
	cout << maxSubarraySum(arr, arr.size()) << endl;

	return 0;
}