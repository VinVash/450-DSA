#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for(auto i: nums) {
        pq.push(i);
    }
    for(int i = 0; i < k-1; i++) {
        pq.pop();
    }
    return pq.top();
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}