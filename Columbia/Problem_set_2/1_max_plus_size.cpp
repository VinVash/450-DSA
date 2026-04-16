#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0; i< n; i++) {
		cin >> arr[i];
	}

	int odd_sum = 0, even_sum = 0;

	int maxi = 0;
	for(int i = 0; i< n; i++) {
		if(i%2 == 0) {
			even_sum += 1;
			maxi = max(maxi, arr[i]);
		}
	}
	even_sum += maxi;

	maxi = 0;
	for(int i = 0; i< n; i++) {
		if(i%2 == 1) {
			odd_sum += 1;
			maxi = max(maxi, arr[i]);
		}
	}
	odd_sum += maxi;

	cout << max(even_sum, odd_sum) << endl;


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