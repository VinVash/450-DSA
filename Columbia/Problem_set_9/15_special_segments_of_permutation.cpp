#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;

    vector<int> p(n+1);
    vector<int> pos(n+1); // pos tracker
    for (int i =1; i <=n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    vector<int> l(n+1, 0);
    vector<int> r(n+1, n+1);
    vector<int> st;

    for (int i =1; i <=n; i++) {
        while (!st.empty() && p[st.back()] <p[i]) {
            r[st.back()] =i;
            st.pop_back();
        }
        if (!st.empty()) {
            l[i] = st.back();
        }
        st.push_back(i);
    }

    long long ans = 0;

    for (int i =1; i <=n; i++) {
        int left = l[i], right=r[i];

        if (i - left < right - i) {
            for (int j = left+1; j <i; j++) {
                int target = p[i] - p[j];
                if (target > 0 && target <= n && pos[target] > i && pos[target] < right) {
                    ans++;
                }
            }
        } else {
            for (int j = i+1; j < right; j++) {
                int target = p[i] - p[j];
                if (target > 0 && target <= n && pos[target] > left && pos[target] < i) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}