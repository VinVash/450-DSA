#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;

	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	for(int x: arr) {
		if(x == 67) {
			cout << "YES" << endl;
			return;
		}
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

    // solve();

    return 0;
}