#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    double maxi = 0.0;

    for (int i =1; i <=n; i++) {
        maxi += 1.0 / i;
    }

    
    cout << fixed << setprecision(12) << maxi << endl;
	
}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve();

	return 0;

}