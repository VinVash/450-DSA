#include <bits/stdc++.h>
using namespace std;

long long int count(int S[], int m, int n) {
    vector<int> table(n+1, 0);

    table[0] = 1; // only 1 way to make 0 money, i.e., take no coins.

    for(int i = 0; i < m; i++) {
        for(int j = S[i]; j <= n; j++) {
            table[j] += table[j - S[i]];
        }
    }

    return table[n];
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> arr(n);

    for(int i=0; i < n; i++)
        cin >> arr[i];

    cout << maxProduct(arr, n) << endl;

    return 0;
}
