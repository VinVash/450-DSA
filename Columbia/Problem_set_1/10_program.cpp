#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m; cin >> n >> m;

	string s; cin >> s;

	vector<pair<int, int>> queries;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		queries.push_back({ x, y  });
	}

	vector<int> pre(n+1);
	vector<int> min_pre(n+1);
	vector<int> max_pre(n+1);

	for(int i = 0; i < n; i++) {
		int val = (s[i] == '-' ? -1 : 1);
		pre[i+1] = pre[i]+val;
		min_pre[i+1] = min(min_pre[i], pre[i+1]);
		max_pre[i+1] = max(max_pre[i], pre[i+1]);
	}

	vector<int> min_suff(n+2, INT_MAX);
	vector<int> max_suff(n+2, -INT_MAX);

	for(int i = n; i >= 1; i--) {
		min_suff[i] = min(min_suff[i+1], pre[i]);
		max_suff[i] = max(max_suff[i+1], pre[i]);
	}

	for(int i = 0; i< m;i ++) {
		int l = queries[i].first, r = queries[i].second;

		int curr_min = min_pre[l-1];
		int curr_max = max_pre[l-1];

		if(r < n) {
			int shift = pre[l-1] - pre[r];

			curr_min = min(curr_min, min_suff[r+1] + shift);
			curr_max = max(curr_max, max_suff[r+1] + shift);
		}

		cout << (curr_max - curr_min + 1) << endl;
	}
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