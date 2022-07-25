#include <bits/stdc++.h>
using namespace std;

int m_step_xor(vector<int> &arr, int m, int k) {
	int n = arr.size();

	if(k >= n-m)
		return -1; // k is greater than the resulting array size.

	for(int i = 0; i < 18; i++) { // considering m < 2^18
		// check if ith bit is set or not in m
		if(m & (1 << i)) {
			m -= (1 << i);

			for(int j = 0; j < n - (1 << i); j++) {
				arr[j] = arr[j] ^ arr[j + (1 << i)];
			}
		}
	}

	return arr[k];
}

// For every 2^k th operation a[i]=a[i]^a[i+(2^k)]  for : i<n-2^k
// Since 1 << i means 1 is left-shifted i times, it is equal to 2^i.
// or 1 << k = 2^k.

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> arr {1, 4, 5, 6, 7};

	int m = 1, k = 2;

	cout << m_step_xor(arr, m, k) << endl;

	return 0;
}