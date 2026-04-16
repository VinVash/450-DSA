#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;

    char mini = s[0];
        
    for (int i = 0; i < s.size(); i++) {
        if (s[i] <= mini) {
            mini = s[i];
            cout << "Mike" << endl;
        } else {
            cout << "Ann" << endl;
        }
    }

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