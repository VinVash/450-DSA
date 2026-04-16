#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; 
    cin >> n >> k;
    string s;
    cin >> s;

    int l = -1, r = -1;
    for(int i = 0; i < n; i++)
        if(s[i] == '*') { l = i; break; }

    for(int i = n-1; i >= 0; i--)
        if(s[i] == '*') { r = i; break; }

    // only one '*'
    if(l == r) {
        cout << 1 << endl;
        return;
    }

    int ans = 1; // first x
    int curr = l;

    while(curr + k < r) {
        int nxt = curr;
        for(int i = curr + 1; i <= curr + k; i++) {
            if(s[i] == '*') nxt = i;
        }
        curr = nxt;
        ans++;
    }

    // last x
    ans++;
    cout << ans << endl;


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