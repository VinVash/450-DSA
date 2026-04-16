#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n, k;
	cin >> n >> k;

	vector<int> pos(k), temp(k);

	for(int i = 0; i < k; i++) cin >> pos[i];
	for(int i = 0; i < k; i++) cin >> temp[i];

	vector<int> temps(n, 2*1e9); // 1e9 is the max temperature limit
	for(int i = 0; i < k; i++) {
		temps[pos[i]-1] = temp[i];
	}

	vector<int> left(n, 2*1e9);
	for(int i = 0; i < n; i++) {
		if(i == 0) {
			left[i] = temps[i];
			continue;
		}
		left[i] = min(left[i-1]+1, temps[i]);
	}
	
	vector<int> right(n, 2*1e9);
	for(int i = n-1; i >= 0; i--) {
		if(i == n-1) {
			right[i] = temps[i];
			continue;
		}
		right[i] = min(right[i+1]+1, temps[i]);
	}

	for(int i = 0; i < n; i++) {
		temps[i] = min(left[i], right[i]);
	}
	for(int x: temps) cout << x << " ";
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