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

int solve(Node* node, int& ans) {
    if(node == NULL)
        return 0;
        
    int curr = node->data + solve(node->left, ans) + solve(node->right, ans);
    
    ans = max(ans, curr);
    
    return curr;
}

int findLargestSubtreeSum(Node* root) {
    if(root == NULL)
        return 0;
    
    int ans = INT_MIN;
    
    solve(root, ans);
    
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);
  
    cout << findLargestSubtreeSum(root) << endl;

	return 0;
}