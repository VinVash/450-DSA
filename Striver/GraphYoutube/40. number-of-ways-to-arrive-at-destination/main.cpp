#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: ElogV (simply Dijkstra's algo)
// Space complexity: O(N)

int countPaths(int n, vector<vector<int>>& roads) {

	int cnt = 0;
    int mod = 1e9 + 7;
    
    vector<pair<int, int>> adj[n];
    
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;
    
    vector<int> dist(n, INT_MAX);
    vector<int> ways(n, 0);
    
    //
    for(auto it : roads){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        
        adj[u].push_back({v,w}); 
        adj[v].push_back({u,w}); 
        
    }
    
    pq.push({0, 0}); // {dist, lastNode}
    dist[0] = 0;
    ways[0] = 1;
    
    while(!pq.empty()){
        
        int node = pq.top().second;
        pq.pop();
        
        //
        for(auto it : adj[node]){
            
            int v = it.first;
            int edgeWeight = it.second; // for, (u to v)
            
            if(dist[node] + edgeWeight < dist[v]){ // if(d + edgeWeight <= dist[v]){...}
            
                dist[v] = dist[node] + edgeWeight;
                
                pq.push({dist[v], v});
                
                ways[v] = ways[node];
            }
            else if(dist[node] + edgeWeight == dist[v]){
                ways[v] += ways[node];
            }
        }
        
    }
    
    //
    return ways[n-1];


}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}