#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q, d; cin >> q >> d;

    for(int i = 0; i < q; i++) {
        int a; cin >> a;


        if(a >= 10*d) {
            cout << "YES" << endl;
            continue;
        }

        bool possible = false;
        for(int n = 1; n <= 10; n++) {
            int current_multiple = n * d;
            if (current_multiple <= a && current_multiple % 10 == a % 10) { // units digit are same
                possible = true;
                break;
            }
        }

        if(possible) cout << "YES" << endl;
        else cout << "NO" << endl;


    }



}


int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--) {
    	solve();
    }

    return 0;
}