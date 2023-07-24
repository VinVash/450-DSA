#include <bits/stdc++.h>
using namespace std;

int PalinArray(vector<int> &a, int n) {
	for(int i = 0; i < n; i++) {
	    string str = to_string(a[i]);
	    int s = str.size();
	    
	    for(int j = 0; j < s/2; j++) {
	        swap(str[j], str[s-j-1]);
	    }
	    if(a[i] != stoi(str))
	        return 0;
	}
	return 1;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int t; cin >> t;

	while(t) {
		int n; cin >> n;
		vector<int> nums(n);

		for(int i = 0; i < n; i++)
		    cin >> nums[i];

		cout << PalinArray(nums, n) << endl;

		t--;
	}

	return 0;
}