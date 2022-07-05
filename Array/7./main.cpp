#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &arr, int n)
{
    int temp = arr[n-1];
    
    for(int i = n-2; i >= 0; i--)
        arr[i+1] = arr[i];
        
    arr[0] = temp;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> arr {1, 2, 3, 4, 5, 6, 7};
	rotate(arr, arr.size());

	for(int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;


	return 0;
}