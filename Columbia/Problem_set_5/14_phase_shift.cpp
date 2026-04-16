#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string t; cin >> t;

    vector<int> to(26, -1);
    vector<bool> used(26, false);
    
    for (char c : t) {
        int x = c - 'a';
        
        if (to[x] == -1) {
            for (int y = 0; y < 26; y++) {
                if (used[y]) continue;
                
                
                int curr = y;
                int len = 1;
                while (to[curr] != -1) {
                    curr = to[curr];
                    len++;
                }
                
                
                if (curr == x && len < 26) {
                    continue;
                }
                
                // valid mapping
                to[x] = y;
                used[y] = true;
                break;
            }
        }
        
        cout << (char)(to[x] + 'a');
    }
    cout << endl;
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

    // solve();

	return 0;

}