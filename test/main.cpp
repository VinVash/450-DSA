#include <bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n) {
    int pmax, nmax; // denotes the positive and negative maxes at any time.
    int res; // stores the result.
    
    pmax = nmax = arr[0];
    
    for(int i=1; i < n; i++) {
       // arr[i] denotes the current element we are accessing.
       if(arr[i] > 0) { // positive.
           pmax = max((long long)arr[i], pmax * (long long)arr[i]);
           nmax = min((long long)arr[i], nmax * (long long)arr[i]);
       } else {
           nmax = min((long long)arr[i], pmax * (long long)arr[i]);
           pmax = max((long long)arr[i], nmax * (long long)arr[i]);
       }
       
       res = max(pmax, nmax);
    }
    
    return res;
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
