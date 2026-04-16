#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int bad = 0;
    int mini = a[n - 1]; 
    
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > mini) {
            bad++;
        } else {
            mini = a[i];
        }
    }
    
    cout << bad << endl;
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