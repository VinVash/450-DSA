#include <bits/stdc++.h>
using namespace std;

// 6 -> 12 -> 24 -> 48
// 6 -> 3 ->

// 14  3  
// 14 7 


//               1
//        2             14
//    4      5      12        7
// 8   9  10  11  6   13    3   15  



int check(int x) {
	while(x % 2 == 0) x /= 2;
	return x;
}

void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	bool flag = true;
	for(int i = 0; i < n; i++) {
		int a; cin >> a;

		if(check(a) != check(i+1)) {
			flag = false;
		}
	}

	cout << (flag ? "YES" : "NO") << endl;



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

    // solve();

    return 0;
}