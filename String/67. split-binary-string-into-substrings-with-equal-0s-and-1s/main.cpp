#include <bits/stdc++.h>
using namespace std;

int maxSubstr(string s, int n) {
	int count0 = 0, count1 = 0;
	int count = 0;

	for(int i = 0; i < n; i++) {
		if(s[i] == '0')
			count0++;
		else
			count1++;

		if(count0 == count1)
			count++;
	}

	if(count0 != count1)
		return -1;

	return count;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s; cin >> s;
	int n = s.size();

	cout << maxSubstr(s, n) << endl;


	return 0;
}