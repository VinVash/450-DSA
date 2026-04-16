#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> b(n);
	for(int i = 0; i< n; i++) {
		cin >> b[i];
	}
	if(n == 1) {
		cout << b[0] << endl;
		return;
	}

	unordered_map<int, long long> mp;

	for(int i = 0; i< n; i++) {
		int temp = i - b[i];

		if(mp.find(temp) != mp.end()) {
			mp[temp] += b[i];
		} else {
			mp[temp] = b[i];
		}
	}

	long long maxi = 0;
	for(const auto& pr: mp) {
		maxi = max(maxi, pr.second);
	}

	cout << maxi << endl;
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