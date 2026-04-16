#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int count = 0;

	for(int i = 0; i< n-2; i ++) {
		if(s.substr(i, 3) == "pie" || s.substr(i, 3) == "map") {
			count++;

			i += 2;
		}
	}

	cout << count << endl;
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