#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if(n == 1) {
        cout << 1 << endl;
        return;
    }

    int diff = 0;
    bool flag = false;

    for(int i = 0; i < n; i++) {
        int j = (i+1) % n;
        if(s[i] != s[j]) diff++;
        else flag = true;
    }
    cout << (flag ? diff+1 : diff) <<endl;

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