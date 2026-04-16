#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<long long> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	long long a = 0, b = 0;
	for(int i = 0; i< n; i++) {
		if(i % 2 == 0) {
			if(arr[i] % 2 == 0) a += arr[i];
		} else {
			if(arr[i] % 2 == 1) b += arr[i];
		}
	}

	if(a > b) cout << "Alice" << endl;
	else if (b > a) cout << "Bob" << endl;
	else cout << "Tie" << endl;
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