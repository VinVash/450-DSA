#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    // solution exists only if n/2 is even (i.e., n is a multiple of 4)
    if ((n / 2) % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    vector<int> a;
    int even_sum = 0;
    int odd_sum = 0;

    // 1) Fill the first half with even numbers
    for (int i = 1; i <= n / 2; i++) {
        int val = i * 2;
        a.push_back(val);
        even_sum += val;
    }

    // 2) Fill the first (n/2 - 1) elements of the second half with odd numbers
    for (int i = 1; i < n / 2; i++) {
        int val = (i * 2) - 1;
        a.push_back(val);
        odd_sum += val;
    }

    // 3) The last element is the difference to make the sums equal
    a.push_back(even_sum - odd_sum);

    // Print the result
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " "); // no space after printing the last element
    }
    cout << endl;
}

int main() {

    // no. of testcases
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}