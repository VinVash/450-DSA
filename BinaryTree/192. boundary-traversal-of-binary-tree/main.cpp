#include <bits/stdc++.h>
using namespace std;

vector<int> printLeaves(Node *node, vector<int> &res) {
    if(node == nullptr)
        return res;
        
    printLeaves(node->left, res);
    printLeaves(node->right, res);
    
    if(!node->left && !node->right)
        res.push_back(node->data);
        
    return res;
}

vector<int> printLeftBoundary(Node *node, vector<int> &res) {
    if(node == nullptr)
        return res;
        
    if(node->left) {
        res.push_back(node->data);
        printLeftBoundary(node->left, res);
    } else if(node->right) {
        res.push_back(node->data);
        printLeftBoundary(node->right, res);
    }
    
    return res;
}

vector<int> printRightBoundary(Node* root, vector<int> &res) {
    if (root == nullptr)
        return res;
 
    if (root->right) {
        // to ensure bottom up order, first call for right subtree, then print this node
        printRightBoundary(root->right, res);
        res.push_back(root->data);
    }
    else if (root->left) {
        printRightBoundary(root->left, res);
        res.push_back(root->data);
    }
    
    return res;
}

vector <int> boundary(Node *root) {
    vector<int> res;
    
    if(root == nullptr)
        return res;
        
    res.push_back(root->data);
    
    vector<int> res1, res2, res3;
    
    printLeftBoundary(root->left, res1);
    printLeaves(root->left, res2);
    printLeaves(root->right, res2);
    printRightBoundary(root->right, res3);
    
    for(auto i: res1)
        res.push_back(i);
        
    for(auto i: res2)
        res.push_back(i);
        
    for(auto i: res3)
        res.push_back(i);
        
    return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}