#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b) {
	if(a == b) return false;
	if(a + b == 7) return false;
	return true;
}

void solve() {

	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i< n; i++) cin >> a[i];

	vector<vector<int>> dp(n, vector<int>(7, INT_MAX));

	for(int j = 1; j <= 6; j++) {
		if(a[0] == j) {
			dp[0][j] = 0;
		} else {
			dp[0][j] = 1;
		}
	}

	for(int i = 1; i < n; i++) {
		for(int curr_no = 1; curr_no <= 6; curr_no++) {
			for(int prev_no = 1; prev_no <= 6; prev_no++) {

				if(check(curr_no, prev_no)) { // adjacent
					int cost = (a[i] == curr_no) ? 0 : 1;
					dp[i][curr_no] = min(dp[i][curr_no], dp[i-1][prev_no] + cost);
				}
			}
		}
	}

	int ans = INT_MAX;
	for(int j = 1; j <= 6; j++) {
		ans = min(ans, dp[n-1][j]);
	}

	cout << ans << endl;

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

    // solve();

    return 0;
}