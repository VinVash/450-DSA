#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0; i< n; i++) {
		cin >> arr[i];
	}

	long long even_sum = 0, odd_sum = 0;

	for(int i = 0; i < n; i++) {
		if(i % 2 == 0) {
			even_sum += arr[i];
		} else {
			odd_sum += arr[i];
		}
	}

	for(int i = 0; i< n; i++) {
		if(even_sum < odd_sum) {
			if(i % 2 == 0) {
				arr[i] = 1;
			}
		} else {
			if(i % 2 == 1) {
				arr[i] = 1;
			}
		}
	}

	for(int x: arr) cout << x << " ";
		cout << endl;


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