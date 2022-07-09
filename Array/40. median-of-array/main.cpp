#include <bits/stdc++.h>
using namespace std;

int find_median(vector<int> v) {
    sort(v.begin(), v.end());
    int n = v.size();
    
    if(n % 2 == 0) {
        return (v[n/2-1] + v[n/2]) / 2;
    } else {
        return v[n/2];
    }
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

    cout << find_median(nums) << endl;

	return 0;
}