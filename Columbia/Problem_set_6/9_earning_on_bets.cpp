#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

void solve() {

    int n;
    cin >> n;
    vector<int> k(n);
    long long curr_lcm = 1;
    
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        curr_lcm = lcm(curr_lcm, (long long)k[i]);
    }

    vector<long long> x(n);
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        x[i] = curr_lcm / k[i];
        total += x[i];
    }

    if (curr_lcm > total) {
        for (int i = 0; i < n; i++) {
            cout << x[i] << (i == n-1 ? "" : " ");
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
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

    // solve();

	return 0;

}