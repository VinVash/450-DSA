#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	int j = 0;

	for(int k = 1; k <= n; k++) {

		// smallest j such that a[j] + 1 <= k+1 - j
		while(j < n && arr[j] < k-j) {
			j++;
		}

		cout << k-j << " ";
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

    int t; cin >> t;

    while(t--) {
    	solve();
    }


	return 0;
}