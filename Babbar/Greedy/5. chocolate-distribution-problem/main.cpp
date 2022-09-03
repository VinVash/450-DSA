#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m) {
	sort(a.begin(), a.end());
	long long l = 0, r = m-1;
	long long mini = INT_MAX;

	while(r < n) {
		mini = min(mini, a[r] - a[l]);
		l++;
		r++;
	}

	return mini;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}