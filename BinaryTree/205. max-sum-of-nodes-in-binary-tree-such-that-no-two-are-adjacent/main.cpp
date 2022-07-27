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

unordered_map<Node*, int> umap;

int maxSum(Node* node) {
	if(node == nullptr) return 0;

	if(umap[node]) return umap[node];

	int inc = node->data; // initialise the included sum to the node->data, then add the maxSum of its grandchildren.
	if(node->left)
		inc += maxSum(node->left->left) + maxSum(node->left->right);
	if(node->right)
		inc += maxSum(node->right->left) + maxSum(node->right->right);

	int exc = maxSum(node->left) + maxSum(node->right);

	umap[node] = max(inc, exc);
	return umap[node];
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