#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll a; cin >> a;
    string s; cin >> s;

    int n = s.size();
    
    vector<ll> cnt(36005, 0); // max possible sum of substr = 4k * 9
    ll total = 0;

    for (int i = 0; i < n; i++) {
        ll curr = 0;
        for (int j = i; j < n; j++) {
            curr += (s[j] - '0');
            cnt[curr]++;
            total++;
        }
    }

    ll ans = 0;

    if (a == 0) {
        ans = cnt[0] *total*2LL - cnt[0] *cnt[0];
    } else {
        for (int i = 1; i <=36000; i++) {
            if (a % i == 0) {
                ll j = a /i;
                if (j <= 36000) {
                    ans += cnt[i] *cnt[j];
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();

    return 0;
}