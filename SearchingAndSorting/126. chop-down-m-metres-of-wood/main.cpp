#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &trees, int n, int m, int max_height) {
	int res = 0;

	for(auto i: trees) {
		if(i > max_height)
			res += i - max_height;
	}

	if(res >= m)
		return true;
	
	return false;
}

int solve(vector<int> &trees, int n, int m) {
	int ans = 0;

	int low = *min_element(trees.begin(), trees.end());
	int high = *max_element(trees.begin(), trees.end());

	while(low <= high) {
		int mid = (low + high) / 2;
		// cout << mid << endl;

		if(isPossible(trees, n, m, mid)) {
			ans = mid;
			low = mid + 1; // increase the max height.
		} else {
			high = mid - 1;
		}
	}

	return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;
	vector<int> trees(n);
	for(int i = 0; i < n; i++)
	    cin >> trees[i];

	cout << solve(trees, n, m) << endl;

	return 0;
}