#include <bits/stdc++.h>
using namespace std;

vector<int> pos[300005];
int a[300005];

void solve() {
	int n, q; cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]].push_back(i);
	}

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	while(q--) {
		int l, r; cin >> l >> r;
		l--, r--;
		int len = r-l+1;
		int maxi = 0;

		for(int k = 0; k < 40; k++) {
			int random_idx = uniform_int_distribution<int>(l, r)(rng);
			int candidate = a[random_idx];

			int count = upper_bound(pos[candidate].begin(), pos[candidate].end(), r) - lower_bound(pos[candidate].begin(), pos[candidate].end(), l);
			maxi = max(maxi, count);
		}

		cout << max(1, 2*maxi - len) << endl;
	}

	// unordered_map<int, int> freq;
	// for(int i = 0; i < n; i++) {
	// 	if(freq.find(arr[i]) == freq.end()) {
	// 		freq[arr[i]] = 1;
	// 	} else {
	// 		freq[arr[i]]++;
	// 	}
	// }

	// for(int i = 0; i< q; i++) {
	// 	int l, r; cin >> l >> r;
	// 	int len = r-l+1;

	// 	int candidate = 0, count = 0;
	// 	for(int i = l; i <= r; i++) {
	// 		if(count == 0) {
	// 			candidate = arr[i];
	// 			count = 1;
	// 		} else if(arr[i] == candidate) {
	// 			count++;
	// 		} else {
	// 			count--;
	// 		}
	// 	}

	// 	count = 0;
	// 	for(int x: arr) {
	// 		if(x == candidate) count++;
	// 	}

	// 	cout << max(1, 2 * count - len) << endl;

	// }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int t; cin >> t;
    // while(t--) {
    // 	solve();
    // }

    solve();

    return 0;
}