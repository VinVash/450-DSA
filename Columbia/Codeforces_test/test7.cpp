#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n; cin >> n;
 
    double result = 0;
 
    for(int i = 1; i <= n; i++) {
        result += (double)1 / i;
    }
 
    cout << result << endl;
}
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    solve();
 
    return 0;
 
}
