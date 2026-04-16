#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;

	string s; cin >> s;

	string t = s;
	sort(t.begin(), t.end());

	int count = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] != t[i]) count++;
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
