#include <bits/stdc++.h>
using namespace std;

void foo(int *num) {
    cout << "Inside function foo" << endl;
    // num = 8;
    cout << *num << endl;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int a = 5;
    int *b = &a;
    cout << *b << endl;
    foo(b);
    cout << a << endl;
    *b = 9;
    cout << a << endl;

    cout << endl;

    int c = 6;
    int &d = c;
    cout << c << endl;
    foo(&c);
    c = 7;
    cout << d << endl;

	return 0;
}