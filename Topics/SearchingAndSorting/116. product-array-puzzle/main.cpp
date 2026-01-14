#include <bits/stdc++.h>
using namespace std;

vector<int> productArray(vector<int> &arr, int n) {
    vector<int> left(n), right(n);
    vector<int> product(n, 1); // for the edge case where n = 1 and arr = [85].

    if (n == 1) {
        return product;
    }
  	
    int i, j;
  
    // Left most element of left array is always 1.
    left[0] = 1;
  
    // Right most element of right array is always 1.
    right[n - 1] = 1;
  
    // Construct the left array
    for (i = 1; i < n; i++)
        left[i] = arr[i - 1] * left[i - 1];
  
    // Construct the right array
    for (j = n - 2; j >= 0; j--)
        right[j] = arr[j + 1] * right[j + 1];
  
    // Construct the product array using left array and right array
    for (i = 0; i < n; i++)
        product[i] = left[i] * right[i];
  
    return product;
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

	vector<int> res = productArray(nums, n);

	for(auto i: res)
		cout << i << " ";
	cout << endl;

	return 0;
}