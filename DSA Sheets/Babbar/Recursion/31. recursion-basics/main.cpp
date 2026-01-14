#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
	if(n == 0 || n == 1)
		return 1;

	return n * factorial(n-1);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n; cin >> n;

    cout << factorial(n) << endl;

	return 0;
}