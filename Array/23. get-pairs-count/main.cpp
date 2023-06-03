#include <bits/stdc++.h>
using namespace std;

int getPairsCount(vector<int> &arr, int n, int k) {
    sort(arr, arr + n);
    int x = 0, c = 0, y, z;
    for (int i = 0; i < n - 1; i++) {
        x = k - arr[i];
        
        // Lower bound from i+1
        int y = lower_bound(arr + i + 1,
                            arr + n, x) - arr;
          
        // Upper bound from i+1
        int z = upper_bound(arr + i + 1, 
                            arr + n, x) - arr;
        c = c + z - y;
    }
    return c;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int k; cin >> k;
    int n; cin >> n;

    cout << "Value of n: " << n << endl;

    cout << "Value of k: " << k << endl;

    cout << "Input vector: " << endl;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    	cin >> arr[i];

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    int res = getPairsCount(arr, n, k);

	cout << "Final Ans: " << res << endl;

	return 0;
}