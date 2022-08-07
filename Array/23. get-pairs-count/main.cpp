#include <bits/stdc++.h>
using namespace std;

int getPairsCount(vector<int> &arr, int n, int k) {
    sort(arr.begin(), arr.end());
    cout << "Sorted vector: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    int l = 0, r = n-1;
    int res = 0;
    
    // while(j >= i) {
    //     if(arr[i] + arr[j] > k)
    //         j--;
    //     else if(arr[i] + arr[j] < k)
    //         i++;
    //     else {
    //         cout << arr[i] << " " << arr[j] << endl;
    //         int x = 1, y = 1;
    //         while(arr[i+1] == arr[i]) {
    //             i++; x++;
    //             cout << "i :" << i << endl;
    //         }
    //         i++;
    //         while(arr[j-1] == arr[j]) {
    //             j--; y++;
    //             cout << "j :" << j << endl;
    //         }
    //         j--;
            
    //         res += x*y;
    //     }
    // }

    while(l <= r) {
            if(arr[l] + arr[r] > k)
                r--;
            else if(arr[l] + arr[r] < k)
                l++;
            else {
                int x=1, y=1;
                
                while(arr[l] == arr[l+1])
                    l++; x++;
                l++; // to move to the next distinct element.
                
                while(arr[r-1] == arr[r])
                    r--; y++;
                r--; // to move to the next distinct element.
                
                res += x*y;
            }
        }
    
    return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int k; cin >> k;
    int n; cin >> n;

    cout << "Value of n: " << n << endl;

    cout << "Value of k: " << k << endl;

    cout << "Input vector: " << endl;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    	cin >> arr[i];

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    int res = getPairsCount(arr, n, k);

	cout << "Final Ans: " << res << endl;

	return 0;
}