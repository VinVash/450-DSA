#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    int i = 0;
    
    while (i <n && s[i] == 'a') {
        i++;
    }
    
    if (i == n) {
        s[n-1] = 'z';
    } else {
        while (i < n && s[i] != 'a') {
            s[i] = s[i] -1;
            i++;
        }
    }
    
    cout << s << endl;

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