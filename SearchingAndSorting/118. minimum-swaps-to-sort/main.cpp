#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
 }

int minSwaps(vector<int> &arr) {
    int n = arr.size();
    int ans = 0;
    vector<int> temp(arr.begin(), arr.end()); // copy of original arr.
    
    unordered_map<int, int> h;
    
    sort(temp.begin(), temp.end());
    
    for(int i = 0; i < n; i++) {
        h[arr[i]] = i; // which element was at what position originally.
    }
    
    for(int i = 0; i < n; i++) {
        if(arr[i] != temp[i]) {
            ans++; // swap is required.
            int initial = arr[i];
            
            swap(arr, i, h[temp[i]]);
            
            h[initial] = h[temp[i]]; // since the position has been changed.
            h[temp[i]] = i; // changing the swapped out indices.
        }
    }
    
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << minSwaps(nums) << endl;

	return 0;
}