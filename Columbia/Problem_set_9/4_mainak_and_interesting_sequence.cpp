#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    
    if (m <n) {
        cout << "No" << endl;
        return;
    }
    
    if (n %2 !=0) {
        cout << "Yes" << endl;
        for (int i =0; i < n-1; i++) cout << 1 << " ";
        cout << m -n+1 << endl;
    } else {
        if (m %2 !=0) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            for (int i =0; i < n-2; i++) cout << 1 << " ";
            int val = (m -n+2) /2;
            cout << val << " " << val << endl;
        }
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