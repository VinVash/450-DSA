#include <bits/stdc++.h>
using namespace std;



int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		int maxi = 2*n;
		int mini = 2;

		int i = 0;
		while(i < n) {
			if(i < n) {
				cout << maxi << " ";
				maxi -= 2;
				i++;
			}
			if(i < n) {
				cout << mini << " ";
				mini += 2;
				i++;
			}
		}
		cout << endl;

		maxi = 2*n - 1;
		mini = 1;

		i = 0;
		while(i < n) {
			if(i < n) {
				cout << mini << " ";
				mini += 2;
				i++;
			}
			if(i == 1) { // swap these two positions.
				cout << n+1 << " ";
				i++;
				maxi -= 2;
				continue;
			}
			if(i == n-1) { // swap these two positions.
				cout << 2*n-1 << " ";
				i++;
				maxi -= 2;
				continue;
			}
			if(i < n) {
				cout << maxi << " ";
				maxi -= 2;
				i++;
			}
		}
		cout << endl;

	}

	return 0;
}