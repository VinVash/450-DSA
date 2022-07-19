#include <bits/stdc++.h>
using namespace std;

int countTriplets(vector<int> &arr, int sum) {
	int n = arr.size();
	sort(arr.begin(), arr.end());
    int ans = 0;
 
    for (int i = 0; i < n - 2; i++) {

        int j = i + 1, k = n - 1;
 
        while (j < k) {
            if (arr[i] + arr[j] + arr[k] >= sum)
                k--;
 
            else {
                ans += (k - j);
                j++;
            }
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
	int k; cin >> k;

	cout << countTriplets(nums, k) << endl;

	return 0;
}