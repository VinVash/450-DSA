void dfs(int node, vector<int>& vis, vector<int>adjList[]) {
    vis[node] = 1;

    for(auto i: adjList[node]) {
        if(!vis[i]) {
            dfs(i, vis, adjList);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> adjList[n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(isConnected[i][j] == 1) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    
    vector<int> vis(n, 0);
    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            ans++;
            dfs(i, vis, adjList);
        }
    }

    return ans;


}