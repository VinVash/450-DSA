#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr1, vector<int> &arr2) {
	int n = arr1.size(), m = arr2.size();
    int i = 0, j = 0, k = n-1;
    
    while(i <= k && j < m) {
        if(arr1[i] < arr2[j])
            i++;
        else {
            swap(arr1[k], arr2[j]);
            j++; k--;
       }
    }
    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;

	vector<int> arr1(n), arr2(m);

	for(int i = 0; i < n; i++)
	    cin >> arr1[i];

	for(int i = 0; i < m; i++)
	    cin >> arr2[i];

	merge(arr1, arr2);

	for(int i = 0; i < arr1.size(); i++)
		cout << arr1[i] << " ";
	cout << endl;

	for(int i = 0; i < arr2.size(); i++)
		cout << arr2[i] << " ";
	cout << endl;

	return 0;
}