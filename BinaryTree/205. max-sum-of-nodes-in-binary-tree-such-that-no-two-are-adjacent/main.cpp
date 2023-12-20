#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;

	Node(int val) {
		this->data = val;
		this->left = this->right = nullptr;
	}
};

unordered_map<Node*, int> mp;

int solve(Node* node) {
    if(node == NULL)
        return 0;
    if(mp[node])
        return mp[node];
        
    int inc = node->data;
    if(node->left)
        inc += solve(node->left->left) + solve(node->left->right);
    if(node->right)
        inc += solve(node->right->left) + solve(node->right->right);
        
    int exc = solve(node->left) + solve(node->right);
    
    mp[node] = max(inc, exc);
    return mp[node];
    
}

int getMaxSum(Node *root) {
    
    return solve(root);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Node* root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->right = new Node(3);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(5);
    
    cout << maxSum(root) << endl;

	return 0;
}