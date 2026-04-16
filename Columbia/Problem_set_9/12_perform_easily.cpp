#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {

    int a[6];
    for (int i = 0; i < 6; i++) cin >> a[i];

    int n; cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        for (int j = 0; j < 6; j++) {
            v.push_back({b - a[j], i});
        }
    }

    sort(v.begin(), v.end());

    int l = 0, d = 0;
    int mini = 2e9;
    vector<int> c(n, 0);

    for (int r = 0; r < v.size(); r++) {
        if (c[v[r].second] == 0) d++;
        c[v[r].second]++;

        while (d ==n) {
            mini = min(mini, v[r].first - v[l].first);
            c[v[l].second]--;
            if (c[v[l].second] == 0) d--;
            l++;
        }
    }

    cout << mini << endl;

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