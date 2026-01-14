#include <bits/stdc++.h> 
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
    vector<int> temp(n, 0);
    pair<int, int> ans;
    for(int i = 0; i < n; i++) {
        if(temp[arr[i]-1] == 0)
            temp[arr[i]-1] = 1;
        else if(temp[arr[i]-1] == 1) {
            ans.second = arr[i];
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(temp[i] == 0) {
            ans.first = i+1;
            break;
        }
    }
    
    return ans;
}


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> nums {1, 3, 5, 4, 4};
    int n = nums.size();

    pair<int, int> ans = missingAndRepeating(nums, n);
    cout << ans.first << " " << ans.second << endl;


    return 0;
}