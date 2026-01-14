#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    vector<int> dist(n, 1e8);
    
    for(int i = 0; i < n-1; i++) {
        dist[i] = 0;
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    
   // Nth time checking for negative cycle
   
    for(int i = 0; i < n; i++) {
        for(auto it: edges) {
	        int u = it[0];
	        int v = it[1];
	        int wt = it[2];
	        
	        if(dist[u] != 1e8 && dist[u] + wt < dist[v])
	            return 1;
	    }    
    }
    
    return 0;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}