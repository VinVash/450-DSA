#include <bits/stdc++.h>
using namespace std;

int last_seen[50005];

void solve(int tc) {
	int m; cin >> m;

	vector<vector<int>> days(m);
	for(int i = 0; i < m; i++) {
		int n; cin >> n;
		days[i].resize(n);
		for(int j = 0; j < n; j++) {
			cin >> days[i][j];
		}
	}

	vector<int> ans(m);

	for(int i = m-1; i >= 0; i--) {
		int winner = -1;

		for(int x: days[i]) {
			if(last_seen[x] != tc) {
				winner = x;
			}
			last_seen[x] = tc;
		}

		if(winner == -1) {
			cout << -1 << endl;
			return;
		}
		ans[i] = winner;
	}

	for(int i = 0; i < m; i++) {
		cout << ans[i] << (i == m-1 ? "" : " ");
	}
	cout << endl;
}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    for(int i = 0; i < 50005; i++) {
    	last_seen[i] = -1;
    }

    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
    	solve(tc);
    }

    return 0;



}