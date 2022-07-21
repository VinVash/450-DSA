#include <bits/stdc++.h>
using namespace std;

struct Job {
	int start, finish, profit;
};

bool myfunction(Job s1, Job s2) {
	return (s1.finish < s2.finish);
}

// A Binary Search based function to find the latest job
// (before current job) that doesn't conflict with current
// job. "index" is index of the current job. This function
// returns -1 if all jobs before index conflict with it.
// The array jobs[] is sorted in increasing order of finish
// time.
int binarySearch(Job jobs[], int index)
{
	// Initialize 'lo' and 'hi' for Binary Search
	int lo = 0, hi = index - 1;

	// Perform binary Search iteratively
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (jobs[mid].finish <= jobs[index].start)
		{
			if (jobs[mid + 1].finish <= jobs[index].start)
				lo = mid + 1;
			else
				return mid;
		}
		else
			hi = mid - 1;
	}

	return -1;
}

int findMaxProfit(Job arr[], int n) {
	// Sort jobs according to finish time
	sort(arr, arr+n, myfunction);

	// table[i] stores the profit for jobs till arr[i] (including arr[i])
	vector<int> table(n);
	table[0] = arr[0].profit;

	// Fill entries in table[] using recursive property
	for (int i = 1; i < n; i++) {
		// Find profit including the current job
		int inclProf = arr[i].profit;
		int l = binarySearch(arr, i);
		if (l != -1)
			inclProf += table[l]; // adding current profit to the largest profit achievable till index l.

		// Store maximum of including and excluding
		table[i] = max(inclProf, table[i-1]);
	}
	
	return table[n-1];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Job arr[] = { {3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200} };
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Optimal profit is " << findMaxProfit(arr, n) << endl;
	
	return 0;
}
