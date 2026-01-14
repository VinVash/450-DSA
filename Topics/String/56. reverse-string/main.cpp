#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
  int l = 0, r = s.size()-1;
  
  while(l < r) {
    swap(s[l], s[r]);
    l++; r--;
  }
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
	vector<char> s(n);

	for(int i = 0; i < n; i++)
		cin >> s[i];

	reverseString(s);

	for(int i = 0; i < n; i++)
		cout << s[i] << " ";
	cout << endl;

	return 0;
}