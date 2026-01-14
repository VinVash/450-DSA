#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long>& a, long long n) {
    for(long long i = 2; i <= n-1; i++) { // first pass.
        if(a[i] < a[i-1]) { // increment a[i] and a[i+1]
            long long temp = a[i-1] - a[i];
            a[i] += temp;
            a[i+1] += temp;
        }
    }

    for(long long i = n-1; i >= 2; i--) { // second pass.
        if(a[i] > a[i+1]) {
            long long temp = a[i] - a[i+1];
            a[i] -= temp;
            a[i-1] -= temp;
        }
    }

    bool flag = true;
    for(long long i = 2; i <= n; i++)
            if(a[i] < a[i-1]) flag = false;

    cout << (flag ? "YES\n" : "NO\n");
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    long long t; cin >> t;

    while(t--) {
        long long n; cin >> n;
        vector<long long> a(n+1);
        for(long long i = 1; i <= n; i++)
            cin >> a[i];

        solve(a, n);
    }

        
    return 0;
    
}