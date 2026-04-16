#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n, k; cin >> n >> k;
	vector<long long> h(n), p(n);
	for(int i = 0; i < n; i++) cin >> h[i];
	for(int i = 0; i < n; i++) cin >> p[i];

	vector<pair<long long, long long>> monsters(n);
	for(int i = 0; i < n; i++) {
		monsters[i] = { h[i], p[i] };

	}

	sort(monsters.begin(), monsters.end());
	vector<long long> min_p(n);

	min_p[n-1] = monsters[n-1].second;

	for(int i = n-2; i >= 0; i--) {
		min_p[i] = min(min_p[i+1], monsters[i].second);
	}

	long long total_damage = 0;
	int idx = 0;

	while(k > 0) {
		total_damage += k;

		while(idx < n && monsters[idx].first <= total_damage) {
			idx++;
		}

		if(idx == n) {
			cout << "YES" << endl;
			return;
		}

		k -= min_p[idx];
	}

	cout << "NO" << endl;




}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
    	solve();
    }
    
    return 0;

}