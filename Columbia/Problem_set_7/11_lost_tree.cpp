#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void solve() {
    int n; cin >> n;
    cout << "? 1" << endl;
    cout.flush();
    
    vector<int> d(n+1);
    vector<int> e;
    vector<int> o;
    
    for (int i =1; i <=n; i++) {
        cin >> d[i];n
        if (d[i] == -1) exit(0);
        if (d[i] %2 ==0) e.push_back(i);
        else o.push_back(i);
    }
    
    vector<pair<int, int>> ans;
    if (e.size() <= o.size()) {
        for (int i =1; i <=n; i++) {
            if (d[i] ==1) {
                ans.push_back({1, i});
            }
        }
        for (int i = 0; i < e.size(); i++) {
            int u = e[i];
            if (u ==1) continue;
            cout << "? " << u << endl;
            cout.flush();
            for (int j =1; j <=n; j++) {
                int dist; cin >> dist;
                if (dist == -1) exit(0);
                if (dist == 1) {
                    ans.push_back({u, j});
                }
            }
        }
    } else {
        for (int i = 0; i < o.size(); i++) {
            int u = o[i];
            cout << "? " << u <<endl;
            cout.flush();
            for (int j =1; j <=n; j++) {
                int dist; cin >> dist;
                if (dist == -1) exit(0);
                if (dist == 1) {
                    ans.push_back({u, j});
                }
            }
        }
    }
    
    cout << "!" << endl;
    for (int i =0; i <ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    cout.flush();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    // return 0;
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve();

    return 0;

}