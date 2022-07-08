#include <bits/stdc++.h>
using namespace std;

int minSwap(vector<int> &arr, int n, int k) {
    int count = 0;
    
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)  count++;
     
    // Find unwanted elements in current
    // window of size 'count'
    int bad = 0;
    for (int i = 0; i < count; ++i)
        if (arr[i] > k) bad++;
     
    // Initialize answer with 'bad' value of
    // current window
    int ans = bad; // current no. of unwanted elements.
    for (int i = 0, j = count; j < n; ++i, ++j) {
         
        // Decrement count of previous window
        if (arr[i] > k)
            bad--;
         
        // Increment count of current window
        if (arr[j] > k)
            bad++;
         
        // minimum amount of swaps needed to bring elements less than k
        // together.
        ans = min(ans, bad);
    }
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << minSwap(nums, n, k) << endl;

	return 0;
}