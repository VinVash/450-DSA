#include <bits/stdc++.h>
using namespace std;



int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    long long t; cin >> t;
    while(t--) {
    	long long n, k; cin >> n >> k;

    	
    	if(k % 2 == 0 && n % 2 != 0) // k -> even, n -> odd.
    		cout << "NO" << endl;
     	else
    		cout << "YES" << endl;

    }

	return 0;
}