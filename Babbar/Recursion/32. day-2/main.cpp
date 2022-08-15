#include <bits/stdc++.h>
using namespace std;

int countDistinctWays(int nStairs) {
	// base case.
	if(nStairs < 0)
		return 0;

	if(nStairs == 0)
		return 1;

	// recursive call.
	return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}

void sayDigits(int n, string arr[]) {
	// base case.
	if(n == 0)
		return;

	// processing.
	int digit = n % 10;
	n = n / 10;

	// recusive call.
	sayDigits(n, arr);

	cout << arr[digit] << " "; // arr[1] stores "one", arr[2] stores "two", ... etc.
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;

	// cout << countDistinctWays(n) << endl;

	string arr[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	sayDigits(n, arr);
	cout << endl;

	return 0;
}
