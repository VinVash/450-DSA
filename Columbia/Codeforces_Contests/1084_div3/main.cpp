#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    set<int> winners;

    for (int s = 0; s < n; s++) {
        vector<int> temp_a = a;
        int remaining = total;
        int current = s;
        int last_eater = -1;

        while (remaining > 0) {
            if (temp_a[current] > 0) {
                temp_a[current]--;
                remaining--;
                last_eater = current + 1;
            }
            current = (current + 1) % n;
        }
        winners.insert(last_eater);
    }

    cout << winners.size() << endl;
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