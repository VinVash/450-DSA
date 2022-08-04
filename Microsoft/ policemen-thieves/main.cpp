#include <bits/stdc++.h>
using namespace std;

int policeTheif(vector<char> &arr, int n, int k) {
	int res = 0;
	vector<int> police;
	vector<int> theif;

	for(int i = 0; i < n; i++) {
		if(arr[i] == 'P')
			police.push_back(i);
		else if(arr[i] == 'T')
			theif.push_back(i);	
	}

	int l = 0, r = 0;
	while(l < theif.size() && r < police.size()) {
		if(abs(theif[l] - police[r]) <= k) {
			res++;
			l++; r++;
		}
		else if(theif[l] < police[r])
			l++;
		else
			r++;
	}

	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, k;
	cin >> n >> k;
	vector<char> arr(n);
	for(int i = 0; i < n; i++)
	    cin >> arr[i];

	cout << policeTheif(arr, n, k) << endl;

	return 0;
}