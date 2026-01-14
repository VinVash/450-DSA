#include <bits/stdc++.h>
using namespace std;

void printLeaves(Node *node, vector<int> &res) {
    if(node == nullptr)
        return;

    if(!node->left && !node->right)
        res.push_back(node->data);
        
    printLeaves(node->left, res);
    printLeaves(node->right, res);
}

void printLeftBoundary(Node *node, vector<int> &res) {
    if(node == nullptr)
        return;
        
    if(node->left) {
        res.push_back(node->data);
        printLeftBoundary(node->left, res);
    } else if(node->right) {
        res.push_back(node->data);
        printLeftBoundary(node->right, res);
    }
}

void printRightBoundary(Node* root, vector<int> &res) {
    if (root == nullptr)
        return;
 
    if (root->right) {
        // to ensure bottom up order, first call for subtree, then print this node
        printRightBoundary(root->right, res);
        res.push_back(root->data);
    }
    else if (root->left) {
        printRightBoundary(root->left, res);
        res.push_back(root->data);
    }
}

vector <int> boundary(Node *root) {
    vector<int> ans;
    if(root == NULL)
        return ans;
        
    ans.push_back(root->data);
        
    vector<int> ans1, ans2, ans3;
    
    printLeftBoundary(root->left, ans1);
    printLeaves(root->left, ans2);
    printLeaves(root->right, ans2);
    printRightBoundary(root->right, ans3);
    
    for(auto i: ans1)
        ans.push_back(i);
    for(auto i: ans2)
        ans.push_back(i);
    for(auto i: ans3)
        ans.push_back(i);
        
    return ans;
    
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}