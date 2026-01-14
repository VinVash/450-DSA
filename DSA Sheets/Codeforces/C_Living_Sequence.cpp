#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    ll t; cin >> t;
    while(t--) {
    	ll k; cin >> k;

    	vector<ll> digits;
    	while(k > 0) {
    		digits.push_back(k % 9);
    		k /= 9;
    	}

    	reverse(digits.begin(), digits.end());

    	for(ll i = 0; i < digits.size(); i++) {
    		cout << (char)(digits[i] < 4 ? (digits[i]+'0') : (digits[i]+'1'));
    	}
    	cout << endl;
    }



	return 0;
}