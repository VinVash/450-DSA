#include <bits/stdc++.h>
using namespace std;

map<Node*, Node*> vis;
Node* dfs(Node* node) {
    if(node == NULL)
        return node;

    if(vis.find(node) != vis.end())
        return vis[node];

    Node* newNode = new Node(node->val);
    vis[node] = newNode;

    for(Node* edges: node->neighbors) {
        newNode->neighbors.push_back(dfs(edges));
    }

    return newNode;
}

Node* cloneGraph(Node* node) {
    Node* clone = dfs(node);

    return clone;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}