#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int res; cin >> res;
    if (res == -1) exit(0);
    return res;
}

void solve() {
	int n; cin >> n;
    
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    
    // shuffle to avoid adversaries
    random_device rd;
    mt19937 g(rd());
    shuffle(p.begin(), p.end(), g);

    int a = p[0], b = p[1];
    int gab = ask(a, b);

    for (int i = 2; i < n; i++) {
        int c = p[i];
        int gbc = ask(b, c);

        if (gab < gbc) {
            a = b; 
            b = c; 
            gab = gbc;
        } else if (gab > gbc) {
            // discard c, a and b remain as is
            // gab remains valid
        } else {
            // gab == gbc. we should discard b. c becomes the new b.
            //  we require new query between a and new b
            b = c;
            gab = ask(a, b);
        }
    }

    cout << "! " << a << " " << b << endl;
    
    // read the validation
    int res; cin >> res;
    if (res == -1) exit(0);
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

    // solve();

    return 0;
}