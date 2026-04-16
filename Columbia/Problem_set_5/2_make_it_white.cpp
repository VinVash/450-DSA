#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int start = -1, end = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'B') {
            start = i;
            break;
        }
    }
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == 'B') {
            end = i;
            break;
        }
    }

    cout << end - start + 1 << endl;

    
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