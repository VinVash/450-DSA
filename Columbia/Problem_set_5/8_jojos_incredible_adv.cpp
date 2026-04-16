#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    
    long long n = s.size();
    string s2 = s + s;
    
    long long maxi_L = 0, curr_L = 0;
    
    for (char c : s2) {
        if (c == '1') {
            curr_L++;
            maxi_L = max(maxi_L, curr_L);
        } else {
            curr_L = 0;
        }
    }
    
    if (maxi_L > n) {
        cout << n * n << endl;
    } else {
        long long w = (maxi_L + 1) / 2;
        long long h = (maxi_L + 2) / 2;
        cout << w * h << endl;
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