#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
	set<pair<int, int>> st;
    vector<int> dis(V, 1e9);
    
    st.insert({ 0, S });
    dis[S] = 0;
    
    while(!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int dist = it.first;
        st.erase(it);
        
        for(auto it: adj[node]) {
            int adjNode = it[0];
            int edgeWeight = it[1];
            
            if(dist + edgeWeight < dis[adjNode]) {
                if(dis[adjNode] != 1e9)
                    st.erase({ dis[adjNode], adjNode });
                    
                dis[adjNode] = dist + edgeWeight;
                st.insert({ dis[adjNode], adjNode });
            }
        }
    }
    
    return dis;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}