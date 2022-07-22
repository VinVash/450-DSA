#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

vector<int> levelOrder(Node* node) {
    vector<int> res;
    queue<Node *> q;
    
    q.push(node);
    
    while(!q.empty()) {
        Node* p = q.front();
        res.push_back(p->data);
        q.pop();
        
        if(p->left != nullptr)
            q.push(p->left);
            
        if(p->right != nullptr)
            q.push(p->right);
            
    }
    
    return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}