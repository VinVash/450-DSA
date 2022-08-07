#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &arr, int n){
        
    if (n <= 1) return 0;
    
    if(arr[0] == 0) return -1; //  we can never reach the end.
    
    int maxReach = arr[0]; // max index we can reach at the moment.
    
    int steps = arr[0]; // no. of steps we can still take in the current jump.
    
    int jump = 1; // made the 1st jump and currently we are during the 1st jump.
    
    for(i = 1; i < n; i++) {
        if(i == n-1) return jump; // if we have reached the end.
        
        steps--;
        maxReach = max(maxReach, i + arr[i]);
        
        if(steps == 0) {
            jump++;
            
            if(i >= maxReach) return -1;
            
            steps = maxReach - i;
        }
    }

    return -1;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> arr {1, 4, 3, 2, 6, 7};
	cout << minJumps(arr, arr.size());


	return 0;
}