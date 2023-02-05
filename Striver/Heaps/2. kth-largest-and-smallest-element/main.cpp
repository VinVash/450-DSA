#include <bits/stdc++.h>
using namespace std;

// O(nlogn) solution - Leetcode solution
vector<int> kthSmallLarge(vector<int> &arr, int n, int k) {
	vector<int> res;

	priority_queue<int, vector<int>, greater<int>> pq2;
	for(auto i: arr) {
		pq2.push(i);
	}
	for(int i = 0; i < k-1; i++) {
		pq2.pop();
	}
	int x = pq2.top();
	res.push_back(x);

	priority_queue<int> pq;
	for(auto i: arr) {
		pq.push(i);
	}
	for(int i = 0; i < k-1; i++) {
		pq.pop();
	}
	x = pq.top();
	res.push_back(x);

	return res;
}

// O(n) solution
int partition(vector<int> &arr, int left, int right, int pivotIndex) 
{
    int pivotValue = arr[pivotIndex];
    
    // Bring pivot element at the end of range.
    swap(arr[pivotIndex], arr[right]); 

    int current = left;
    
    for(int i = left; i < right; i++) 
    {
        if(arr[i] < pivotValue) 
        {
            swap(arr[current], arr[i]);
            current++;
        }
    }
    swap(arr[right], arr[current]);
    
    return current;
}

int quickSelect(vector<int> &arr, int left, int right, int k) 
{
    if(left == right)
    {
        // Size of array is 1.
        return arr[left];
    }
    
    // Note we can select Median as pivot to guaranteed O(N) complexity always.
    int pivotIndex = left + rand() % (right-left+1);
    
    int partitionIndex = partition(arr, left, right, pivotIndex);

    if(partitionIndex >= k)
    {
        // Recur for right subarray
        return quickSelect(arr, left, partitionIndex-1, k);
    }
    
    if(partitionIndex < k-1)
    {
        // Recur for left subarray.
        return quickSelect(arr, partitionIndex+1, right, k);
    }

    return arr[partitionIndex];
}

vector<int> kthSmallLarge2(vector<int> &arr, int n, int k)
{
    vector<int> result(2);
    
    // Kth smallest element
    result[0] = quickSelect(arr, 0, n-1, k);
    
    // Kth largest element
    result[1] = quickSelect(arr, 0, n-1, n-k+1);

    return result;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;

	while(t) {
		int n, k;
		cin >> n >> k;

		vector<int> nums(n);
		for(int i = 0; i < n; i++)
		    cin >> nums[i];

		vector<int> ans = kthSmallLarge(nums, n, k);

		for(auto i: ans)
			cout << i << " ";
		cout << endl;

		t--;
	}

	return 0;
}