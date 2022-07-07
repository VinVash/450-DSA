#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &A) {
	int n = A.size();

    int j = 0;
    int pivot = 0;    // consider 0 as a pivot
 
    // each time we find a negative number, `j` is incremented,
    // and a negative element would be placed before the pivot
    for (int i = 0; i < n; i++)
    {
        if (A[i] < pivot)
        {
            swap(A[i], A[j]);
            j++;
        }
    }
 
    // `j` holds the index of the first positive element
    return j;
}

void rearrange(vector<int> &A) {
	int n = A.size();
    // partition a given array such that all positive elements move
    // to the end of the array
    int p = partition(A);
 
    // swap alternate negative elements from the next available positive
    // element till the end of the array is reached, or all negative or
    // positive elements are exhausted.
 
    for (int i = 0; (p < n && i < p); p++, i += 2) {
        swap(A[i], A[p]);
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

	rearrange(nums);

	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;


	return 0;
}