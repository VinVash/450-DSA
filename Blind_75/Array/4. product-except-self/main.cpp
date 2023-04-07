#include <bits/stdc++.h>
using namespace std;


vector<int> productExceptSelf(vector<int>& nums) {
    int prod = 1;
    int zeroes = 0;

    int n = nums.size();

    vector<int> left(n);
    vector<int> right(n);
    vector<int> ans(n);

    left[0] = 1;
    right[n-1] = 1;

    for(int i = 1; i < n; i++) {
        left[i] = left[i-1] * nums[i-1]; // because we want to store product upto index-1
    }

    for(int j = n-2; j >= 0; j--) {
        right[j] = right[j+1] * nums[j+1]; // because we want to store product upto index+1
    }

    for(int i = 0; i < n; i++) {
        ans[i] = left[i] * right[i];
    }

    return ans;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    return 0;
}