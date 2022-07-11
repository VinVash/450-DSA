#include <bits/stdc++.h>
using namespace std;

bool areRotations(string s1, string s2) {
	if(s1.size() != s2.size())
		return false;

	string temp = s1 + s1;

	return (temp.find(s2) != string::npos);
}

bool checkRotation(string s1, string s2) {
	if(s1.size() != s2.size())
		return false;

	queue<char> q1;
	for(int i = 0; i < s1.size(); i++)
		q1.push(s1[i]);

	queue<char> q2;
	for(int i = 0; i < s2.size(); i++)
		q2.push(s2[i]);

	int target = s2.size();

	while(target) {
		char ch = q2.front();
		q2.pop();
		q2.push(ch);

		if(q2 == q1)
			return true;

		target--;
	}

	return false; // if nothing has been returned till now.
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s1, s2;
	cin >> s1 >> s2;

	// if(areRotations(s1, s2))
	if(checkRotation(s1, s2))
		cout << "Yes, one string is rotation of another" << endl;
	else
		cout << "No, one string is not a rotation of another" << endl;

	return 0;
}