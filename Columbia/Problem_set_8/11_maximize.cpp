#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> a;
vector<ll> p(1, 0);

void solve() {
    int type; cin >> type;

    if (type == 1) {
        ll x; cin >> x;
        a.push_back(x);
        p.push_back(p.back() +x);
    } else {
        int n = a.size();
        int low = 0;
        int high = n-2;
        int best = -1;
        while (low <=high) {
            int mid = low +(high -low) /2;
            if (1LL * (mid+1) *a[mid] <=p[mid] +a[n-1]) {
                best = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        int cnt = best+1;
        double mean = (double)(p[cnt] + a[n-1]) / (cnt+1);
        cout << fixed << setprecision(10) << (double)a[n-1] - mean << endl;
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