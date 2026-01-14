#include <bits/stdc++.h>
using namespace std;

Node *findLCA(Node *node, int n1, int n2) {
    if(node == nullptr) return nullptr;
    
    if(node->data == n1 || node->data == n2)
        return node;
        
    Node *left_lca = findLCA(node->left, n1, n2);
    Node *right_lca = findLCA(node->right, n1, n2);
    
    if(left_lca && right_lca)
        return node;
        
    return (left_lca != nullptr) ? left_lca : right_lca;
}

int findLevel(Node *root, int k, int level) {
    if(root == nullptr)
        return -1;
        
    if(root->data == k)
        return level;
        
    int left = findLevel(root->left, k, level+1);
    
    if(left != -1)
        return left;
    else
        return findLevel(root->right, k, level+1);
}

int findDist(Node* root, int a, int b) {
    Node *LCA = findLCA(root, a, b);
    
    int d1 = findLevel(LCA, a, 0);
    int d2 = findLevel(LCA, b, 0);
    
    return d1 + d2;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}