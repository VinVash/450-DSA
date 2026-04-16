#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int findSmallestDivisor(int value) {
    if (value % 2 == 0) {
        return 2;
    }

    for (int div = 3; div <= sqrt(value); div += 2) {
        if (value % div == 0) {
            return div;
        }
    }
    return value;
}

void solve() {
    int n, k; cin >> n >> k;

    int adder = findSmallestDivisor(n);

    cout << n+ adder + (k-1) * 2 << endl;
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