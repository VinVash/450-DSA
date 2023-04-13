#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
typedef long long ll;

void solve(ll n, ll k) {
	vll ans(n);
	if(k == 0) {
		for(ll i = 0; i < n; i++)
			cout << -1 << " ";
		cout << endl;
	} else {
		for(ll i = 0; i < n; i++) {
			if(k >= n-i) {
				ans[i] = 1000;
				k -= (n-i);
			} else {
				ans[i] = k;
				for(ll j = i+1; j < i+k; j++) // from (i to i+k-1), there will be k positive subarrays.
					ans[j] = -1;
				for(ll j = i+k; j < n; j++)
					ans[j] = -2;
				break;
			}
		}

		for(ll i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
}

signed main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	ll t; cin >> t;
	while(t--) {
		ll n, k; cin >> n >> k;

		solve(n, k);
		
	}

	return 0;
}