#include <bits/stdc++.h>
using namespace std;

int minCountOfNumbers(int n) { // eg: n = 77.
	int k = n % 10; // k = 7.

	int z = n - (9 * (9-k)); // z = 77 - (9 * 2) = 59.

	if(z >= 9 && z % 10 == 9)
		return 10-k;

	else
		return -1;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;

	cout << minCountOfNumbers(n) << endl;

	return 0;
}