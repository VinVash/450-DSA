#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
typedef long long ll;

// (k+1)^2 = n // for minimum k to place n points.

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;


		cout << (ll)sqrt(n-1) << endl;
	}


	return 0;
}