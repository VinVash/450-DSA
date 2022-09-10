#include <bits/stdc++.h>
using namespace std;

class Human {
public:
	int weight;
	int height;

private:
	int age;

public:
	int getAge() {
		return this->age;
	}

	void setWeight(int w) {
		this->weight = w;
	}
};

class Male: public Human {
public:
	string color;

	void sleep() {
		cout << "Male sleeping" << endl;
	}
};

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Male object1;
	cout << object1.age << endl;	
	cout << object1.weight << endl;
	cout << object1.height << endl;

	cout << object1.color << endl;

	object1.setWeight(84);
	cout << object1.weight << endl;

	return 0;
}