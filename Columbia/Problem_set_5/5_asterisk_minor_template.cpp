#include <bits/stdc++.h>
using namespace std;

void solve() {

	string a, b; cin >> a >> b;

	if (a[0] == b[0]) {
        cout << "YES" << endl;
        cout << a[0] << "*" << endl;
        return;
    }

    if (a.back() == b.back()) {
        cout << "YES" << endl;
        cout << "*" << a.back() << endl;
        return;
    }

    for (int i = 0; i < a.size() - 1; i++) {
        string sub = a.substr(i, 2);
        if (b.find(sub) != string::npos) {
            cout << "YES" << endl;
            cout << "*" << sub << "*" << endl;
            return;
        }
    }

    cout << "NO" << endl;

}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

	return 0;

}