#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;

    vector<vector<int>> t(n);
    vector<int> v;

    for (int i =0; i <n; i++) {
        int k; cin >> k;
        for (int j =0; j <k; j++) {
            int x; cin >> x;
            t[i].push_back(x);
            v.push_back(x);
        }
    }

    sort(v.begin(), v.end());

    int g = 0;
    for (int i =0; i <n; i++) {
        int sz = t[i].size();
        for (int j =0; j < sz-1; j++) {
            int a = t[i][j];
            int b = t[i][j+1];
            
            int pos = lower_bound(v.begin(), v.end(), a) -v.begin();
            if (pos+1 <v.size() && v[pos+1] ==b) {
                g++;
            }
        }
    }

    int tot = v.size();
    int s = (tot -n) -g;
    int c = n +s -1;

    cout << s << " " << c << endl;

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