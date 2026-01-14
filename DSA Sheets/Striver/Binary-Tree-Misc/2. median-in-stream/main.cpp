#include <bits/stdc++.h>
using namespace std;

class Solution {
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    int maxi = 0, mini = 0;

public: 
    void insert(int val) {
        max.push(val);
        maxi++;
        min.push(max.top());
        mini++;
        max.pop();
        maxi--;
        
        if(mini > maxi) {
            max.push(min.top());
            maxi++;
            min.pop();
            mini--;
        }
    }
    
    int getMedian() {
        if(maxi > mini) return max.top();
        return (max.top()+min.top())/2;
    }
};

vector<int> findMedian(vector<int> &arr, int n){
    vector<int>ans;
	Solution s;

    for(int i = 0; i < n; i++) {
        s.insert(arr[i]);
        ans.push_back(s.getMedian());
    }
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> nums = {5, 3, 8};
	vector<int> ans = findMedian(nums, nums.size());

	for(int i: ans)
		cout << i << " ";
	cout << endl;

	return 0;
}