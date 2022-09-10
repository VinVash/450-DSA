#include <bits/stdc++.h>
using namespace std;

class Hero {
public:
	int health;
};

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    Hero hero;
    cout << "size: " << sizeof(hero) << endl;

	return 0;
}