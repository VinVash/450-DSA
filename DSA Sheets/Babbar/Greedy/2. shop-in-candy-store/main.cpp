#include <bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int N, int k) {
    sort(candies, candies+N);
    
    int l = 0, r = N-1;
    
    int res1 = 0;
    while(l <= r) {
        res1 += candies[l];
        l++; // since we took one candy
        
        r -= k;
    }
    
    int res2 = 0;
    l = 0, r = N-1;
    while(l <= r) {
        res2 += candies[r];
        r--;
        
        l += k; 
    }
    
    vector<int> res;
    res.push_back(res1);
    res.push_back(res2);
    
    return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}