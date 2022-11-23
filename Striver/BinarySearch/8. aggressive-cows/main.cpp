#include <bits/stdc++.h>
using namespace std;

int isPossible(vector<int> &positions, int n, int cows, int mid) {
    int cnt = 1;
    int lastPlacedCow = positions[0];
    
    for(int i = 1; i < n; i++) {
        if(positions[i] - lastPlacedCow >= mid) {
            cnt++;
            lastPlacedCow = positions[i];
        }
    }
    
    if(cnt >= cows)
        return true;
    return false;
}

int aggressiveCows(vector<int> positions , int n ,  int c){
	sort(positions.begin(), positions.end());
    
    int l = 1, r = positions[n-1] - positions[0];
    while(l <= r) {
        int mid = (l + r) / 2;
        
        if(isPossible(positions, n, c, mid)) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    
    return r;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}