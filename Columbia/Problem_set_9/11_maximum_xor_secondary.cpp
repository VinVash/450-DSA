#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {

    int n; cin >> n;
    
    int maxi = 0;
    stack<int> s;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        
        while (!s.empty() && s.top() <x) {
            maxi = max(maxi, s.top() ^x);
            s.pop();
        }
        
        if (!s.empty()) {
            maxi = max(maxi, s.top() ^x);
        }
        
        s.push(x);
    }
    
    cout << maxi << endl;
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