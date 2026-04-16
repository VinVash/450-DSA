#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n; cin >> n;
	if(n == 1) {
		long long x; cin >> x;
		cout << 0 << endl; // no operations needed
		return;
	}

	vector<long long> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int count = 0;
	long long maxi = arr[n-1];
	for(int i = n-2; i >= 0; i--) {

		if(maxi == 0) {
			cout << -1 << endl;
			return;
		}

		while(arr[i] >= maxi) {
			count++;
			arr[i] /= 2;
		}

		maxi = arr[i];
	}

	cout << count << endl;

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