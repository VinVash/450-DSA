#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        bool flag = s[i] == t[j] || s[i] == '?';
        if (j < t.size() && flag) {
            s[i] = t[j];
            j++;
        } 
        else if (s[i] == '?') {
            s[i] = 'a';
        }
    }
    
    if (j == t.size()) {
        cout << "YES" << endl;
        cout << s << endl;
    } else {
        cout << "NO" << endl;
    }
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