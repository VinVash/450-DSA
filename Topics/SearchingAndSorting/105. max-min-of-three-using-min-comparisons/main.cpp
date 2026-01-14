#include <bits/stdc++.h>
using namespace std;

int midOfThree(int a, int b, int c) {
	int x = a - b;
	int y = b - c;
	int z = a - c;

	if(x * y > 0)
		return b;
	else if(x * z > 0)
		return c;
	else
		return a;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	cout << midOfThree(20, 30, 40) << endl;

	return 0;
}