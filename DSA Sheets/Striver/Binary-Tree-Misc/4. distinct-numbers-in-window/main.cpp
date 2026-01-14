#include <bits/stdc++.h>
using namespace std;

vector<int> dNums(vector<int> &A, int k) {
    int n = A.size();
    unordered_map<int, int> mp;
        
    for(int i = 0; i<k; i++){
        mp[A[i]]++;
    }
    
    vector<int> ans;
    
    ans.push_back(mp.size());
    
    for(int i = k; i<n; i++){
        if(mp[A[i-k]] == 1){
            mp.erase(A[i-k]);
        }
        else{
            mp[A[i-k]]--;
        }
        
        mp[A[i]]++;
        
        ans.push_back(mp.size());
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