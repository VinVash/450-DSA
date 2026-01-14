#include <bits/stdc++.h>
using namespace std;

int minFountains(vector<int> &arr, int n) {
	vector<int>dp(n, -1);

	int idxLeft, idxRight;

	for(int i = 0; i < n; i++) {
		idxLeft = max(i - arr[i], 0); // since it should not be negative.
		idxRight = max(i + (arr[i] + 1), n);
		dp[idxLeft] = max(dp[idxLeft], idxRight);
	}

	int countFountains = 1;

	idxRight = dp[0];

	int idxNext = -1;

	for (int i = 0; i < n; i++) {
        idxNext = max(idxNext, dp[i]);
 
        if (i == idxRight) {
            countFountains++;
            idxRight = idxNext;
        }
    }
 
    return countFountains;
}

int minFountains(vector<int> arr, int n) {
	int min = 0, max = 0, res = 0;

	while(max < n) {
		for(int i = 0; i < n; i++) {
			if(i-arr[i] <= min && i+arr[i] > max) {
				max = i+arr[i];
			}
		}

		if(min == max) return -1;

		res++; // incrementing the count of activated fountains.
		min = max;
	}

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    vector<int> arr {1, 2, 1};
    cout << minFountains(arr, arr.size()) << endl;

	return 0;
}