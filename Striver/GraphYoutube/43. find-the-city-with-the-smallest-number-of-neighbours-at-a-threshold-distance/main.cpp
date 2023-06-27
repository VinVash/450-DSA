#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Floyd Warshall method

int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
	vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
	for(auto it: edges) {
		dist[it[0]][it[1]] = it[2];
		dist[it[1]][it[0]] = it[2];
	}

	for(int i = 0; i < n; i++) dist[i][i] = 0;
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
					continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int countCity = n;
	int cityNo = -1;
	for(int city = 0; city < n; city++) {
		int count = 0;
		for(int adjCity = 0; adjCity < n; adjCity++) {
			if(dist[city][adjCity] <= distanceThreshold)
					count++;
		}

		if(count <= countCity) {
			countCity = count;
			cityNo = city;
		}
	}

	return cityNo;
}


// Dijskstra's method

int finCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
	vector <vector<vector<int>>> adj(n);
    for(int i = 0;i < m;i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    vector <vector<int>> dis(n,vector<int>(n,INT_MAX));
    for(int i = 0;i < n;i++){
        dis[i][i] = 0;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,i});
        while(!pq.empty()){
            int w = pq.top().first,c = pq.top().second;
            pq.pop();
            for(auto it:adj[c]){
                int next = it[0], nw = it[1]+w; // it[1] is the edgeWeight.
                if(dis[i][next] > nw){
                    dis[i][next] = nw;
                    pq.push({nw,next});
                }
            }
        }
    }
    int ans = n-1,mn = INT_MAX;
    for(int i = n-1;i >= 0;i--){
        int r = 0;
        for(int j = 0;j < n;j++)
            if(dis[i][j] <= distanceThreshold) r++;
        if(mn > r){
            mn = r;
            ans = i;
        }
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