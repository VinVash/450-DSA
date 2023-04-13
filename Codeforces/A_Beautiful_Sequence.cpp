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
		vll a(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];

		int flag = false;
		for(int i = 0; i < n; i++) {
			if(i >= a[i]-1) {
				cout << "YES" << endl;
				flag = true;
				break;
			}
		}
		if(!flag)
			cout << "NO" << endl;
	}


	return 0;
}