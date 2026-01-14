#include <bits/stdc++.h>
using namespace std;

class B {
public:
	int a;
	int b;

public:

	int add() {
		return a + b;
	}

	void operator+ (B& obj) {
		
		int val2 = obj.a;
		cout << val2 << endl;
	}
};



int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	B sys, syt;

	sys.a = 3;
	syt.a = 5;

	sys + syt;





	return 0;
}