#include <bits/stdc++.h>
using namespace std;

void solveRec(int i, int sum, vector<int> &ans, vector<int> &arr) {

    if(i == arr.size()) {
        ans.push_back(sum);
        return;
    }
        
    int inc = sum + arr[i];
    int exc = sum;

    
    solveRec(i+1, exc, ans, arr);
    solveRec(i+1, inc, ans, arr);
}

vector<int> subsetSums(vector<int> arr, int N) {
    int i = 0, sum = 0;
    vector<int> ans;
    
    solveRec(i, sum, ans, arr);
    
    return ans;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = subsetSums(nums, n);
    cout << ans.size() << endl;
    for(auto i: ans)
        cout << i << " ";
    cout << endl;

    return 0;
}