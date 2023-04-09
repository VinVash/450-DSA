#include <bits/stdc++.h>
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        vector<int> b(n-1);
        for(int i = 0; i < n-1; i++)
            cin >> b[i];

        vector<int> a;
        a.emplace_back(b[0]);
        for(int i = 0; i < n-2; i++)
            a.emplace_back(min(b[i], b[i+1]));
        
        a.emplace_back(b[n-2]);

        for(auto x: a)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}