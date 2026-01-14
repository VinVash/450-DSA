#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
typedef long long ll;


int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	ll t; cin >> t;
	while(t--) {
		int n;
		ll c, d;
		cin >> n >> c >> d;
		vi a(n);
		map<int, int> mp;

		for(int i = 0; i < n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}

		ll ans = n * c + d; // delete all elements and only add '1'.
		int count = 0;

		for(auto x: mp) {
			count++;
			ans = min(ans, (n - count) * c + (x.first - count) * d);
		}

		cout << ans << endl;

	}
	
	return 0;
}