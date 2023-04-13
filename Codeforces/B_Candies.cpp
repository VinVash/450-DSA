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
		int n; cin >> n;

		if(n % 2 == 0) // even no. cannot be achieved
			cout << -1 << endl;
		else {
			vi v;
			int f = 0;
			for(int i = 29; i >= 1; i--) {
				if((n >> i) & 1) { // if the last bit is 1
					f = 1;
					v.emplace_back(2);
				} else if(f)
					v.emplace_back(1);
			}

			cout << v.size() << endl;
	 		for(auto x: v)
	 			cout << x << " ";
	 		cout << endl;
 		}
	}

	return 0;
}