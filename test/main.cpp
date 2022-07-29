#include <bits/stdc++.h>
using namespace std;



int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, x;
    cin >> n >> x;
    int nums[n];
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << first(nums, x, n) << endl;
    cout << last(nums, x, n) << endl;

    return 0;
}
