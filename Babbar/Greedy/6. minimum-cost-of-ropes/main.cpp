#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n) {
	priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr+n);
	long long res = 0;

	while(pq.size() > 1) {
		long long first = pq.top();
		pq.pop();
		long long second = pq.top();
		pq.pop();

		res += (first + second);
		pq.push(first + second);
	}

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	long long arr[] = {4, 3, 2, 6};
	long long n = sizeof(arr) / sizeof(arr[0]);
	cout << minCost(arr, n) << endl;

	return 0;
}