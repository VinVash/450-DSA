#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string t) {
    int m = s.length();
    int n = t.length();

    vector<vector<int>> DP(2, vector<int>(m+1, 0));
 
    for (int i = 0; i <= m; i++)
        DP[0][i] = i;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j == 0)
                DP[i % 2][j] = i;

            else if (s[j - 1] == t[i - 1]) {
                DP[i % 2][j] = DP[(i - 1) % 2][j - 1];
            }

            else {
                DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j], min(DP[i % 2][j - 1], DP[(i - 1) % 2][j - 1]));
            }
        }
    }
 
    return DP[n % 2][m];
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s, t;
    cin >> s >> t;

    cout << editDistance(s, t) << endl;

    return 0;
}