#include <bits/stdc++.h>
using namespace std;

void findMedian(vector<int> &arr, int n) {

	priority_queue<int> lower;
	priority_queue<int, vector<int>, greater<int>> upper;

	int median;

	for(int size = 1; size <= n; size++) {
		if(!lower.empty() && lower.top() > arr[size-1]) {
			lower.push(arr[size-1]);

			if(lower.size() > upper.size()+1) {
				upper.push(lower.top());
				lower.pop();
			}
		} else {
			upper.push(arr[size-1]);

			if(upper.size() > lower.size()+1) {
				lower.push(upper.top());
				upper.pop();
			}
		}

		if(size % 2 == 1) {
			if(upper.size() > lower.size()) {
				median = upper.top();
			} else {
				median = lower.top();
			}
		} else {
			median = (lower.top() + upper.top()) / 2;
		}

		cout << median << " ";
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

	findMedian(nums, n);

	return 0;
}