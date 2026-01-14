#include <bits/stdc++.h>
using namespace std;

int trappingRainwater(vector<int> vec, int n) {
    int l = 0, r = n-1, lmax = 0, rmax = 0;
    int total = 0;

    while(l < r) {
    	if(vec[l] <= vec[r]) {
    		if(vec[l] > lmax)
    			lmax = vec[l];
    		else
    			total += lmax - vec[l];

    		l++;
    	} else {
    		if(vec[r] > rmax)
    			rmax = vec[r];
    		else
    			total += rmax - vec[r];

    		r--;
    	}
    }

    return total;
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

    cout << trappingRainwater(nums, n) << endl;

	return 0;
}