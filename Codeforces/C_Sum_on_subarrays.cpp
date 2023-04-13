#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
typedef long long ll;

vi solve(int n, int k) {
	vi a;
	if(n == 0)
		cout << endl;
	if(k < n) {
		for(int i = 0; i < n; i++)
			a.emplace_back(-1);
		if(k > 0)
			a[k-1] = 200;
		a[k] = -400;
	} else {
		a = solve(n-1, k-n);
		a.emplace_back(1000);
	}

	return a;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;

		vi ans = solve(n, k);
		for(auto x: ans)
			cout << x << " ";
		cout << endl;
	}

	return 0;
}