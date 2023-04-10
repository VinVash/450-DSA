#include <bits/stdc++.h>
using namespace std;



int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;
	while(t--) {
		int n; char d;
		cin >> n >> d;
		string num;
		cin >> num;

		int i = 0;
		bool flag = d == '0';
		while(i < n) {
			if(d - '0' > num[i] - '0')
				break;
			i++;
		}

		for(int k = 0; k < i; k++) {
			cout << num[k];
		}
		cout << d;
		for(int k = i; k < n; k++)
			cout << num[k];
		cout << endl;

	}


	return 0;
}