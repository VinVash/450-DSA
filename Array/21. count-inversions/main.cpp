#include <bits/stdc++.h>
using namespace std;

long long int merge(vector<int> &arr, vector<int> &temp, int l, int m, int r) {
    int i = l, j = m;
    int k = l;
    
    int inv_count = 0;
    
    while(i <= m-1 && j <= r) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            k++; i++;
        } else {
            temp[k] = arr[j];
            k++; j++;
            
            inv_count += m - i; // inv_count pairs found when the element from the right side is smaller.
        }
    }
    
    while(i <= m-1)
        temp[k++] = arr[i++];
    while(j <= r)
        temp[k++] = arr[j++];
        
    for(i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
    
    return inv_count;
}

long long int mergeSort(vector<int> &arr, vector<int> &temp, int l, int r) {

    int inv_count = 0;
    int mid;
    
    if(r > l) {
        mid = (l + r) / 2;
        
        inv_count += mergeSort(arr, temp, l, mid);
        inv_count += mergeSort(arr, temp, mid+1, r);
        
        inv_count += merge(arr, temp, l, mid+1, r);
    }

    return inv_count;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int n = 5;
	vector<int> temp(n);
	vector<int> arr {2, 4, 1, 3, 5};

    // Array before merge sort.
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

    // Merge sort.
	cout << mergeSort(arr, temp, 0, n-1) << endl;

    // Array after merge sort.
	for(int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;


	return 0;
}
