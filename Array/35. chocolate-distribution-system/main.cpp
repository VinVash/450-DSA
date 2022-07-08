#include <bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int> &a, int n, int m) {
    sort(a.begin(), a.end());
    
    int l = 0, r = m-1;
    
    int minimum = a[r] - a[l];
    
    while(r < n) {
        minimum = min(minimum, a[r]-a[l]);
        l++;
        r++;
    }
    
    return minimum;
    
}   

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n, m;
    cin >> n >> m;
	vector<int> nums(n);

	for(int i = 0; i < n; i++)
	    cin >> nums[i];

	cout << findMinDiff(nums, n, m) << endl;


	return 0;
}