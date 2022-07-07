#include <bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> &arr, int n) {
    long long res = arr[0];
    vector<long long> maxx(n);
    vector<long long> minn(n);
    
    maxx[0] = minn[0] = arr[0];
    
    for(long long i = 1; i < n; i++) {
        if(arr[i] > 0) {
            maxx[i] = max((long long)arr[i], maxx[i-1] * (long long)arr[i]);
            minn[i] = min((long long)arr[i], minn[i-1] * (long long)arr[i]);
        } else {
            maxx[i] = max((long long)arr[i], minn[i-1] * (long long)arr[i]);
            minn[i] = min((long long)arr[i], maxx[i-1] * (long long)arr[i]);
        }
        
        res = max(res, maxx[i]);
    }
    return res;
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

    cout << maxProduct(nums, n) << endl;

	return 0;
}