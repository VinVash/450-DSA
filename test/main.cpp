#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m+n-1; // at the end of nums1
    int a = m-1;
    int b = n-1;
    cout << i << " " << a << " " << b << endl;

    while(a != 0 && b != 0) {
        if(nums1[a] > nums2[b]) {
            nums1[i] = nums1[a];

            a--; i--;
        } else {
            nums1[i] = nums2[b];
            b--; i--;
        }
    }

    while(a != 0) {
        nums1[i] = nums1[a];
        a--; i--;
    }
    while(b != 0) {
        nums1[i] = nums2[b];
        b--; i--;
    }

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> a = {1, 0};
    vector<int> b = {2};

    merge(a, 1, b, 1);

    // cout << "Hello" << endl;


    return 0;
}