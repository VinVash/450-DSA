#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay; // queen
    cin >> bx >> by;
    cin >> cx >> cy;

    if(signbit(bx-ax) != signbit(cx-ax)) {
        cout << "NO";
        return;
    }

    if(signbit(by-ay) != signbit(cy-ay)) {
        cout << "NO";
        return;
    }

    cout << "YES" << endl;


}

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int t; cin >> t;
    // while(t--) {
    // 	solve();
    // }

    solve();


    return 0;
}