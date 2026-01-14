#include <bits/stdc++.h>
using namespace std;

void printLeftBoundary(TreeNode<int>* root, vector<int>& res) {
    if(root == NULL)
        return;

    if(root->left) {
        res.push_back(root->data);
        printLeftBoundary(root->left, res);
    } else if(root->right) {
        res.push_back(root->data);
        printLeftBoundary(root->right, res);
    }
}

void printRightBoundary(TreeNode<int>* root, vector<int>& res) {
    if(root == NULL)
        return;

    if(root->right) {
        printRightBoundary(root->right, res);
        res.push_back(root->data);
    } else if(root->left) {
        printRightBoundary(root->left, res);
        res.push_back(root->data);
    }
}

void printLeaves(TreeNode<int>* root, vector<int>& res) {
    if(root == NULL)
        return;

    printLeaves(root->left, res);
    printLeaves(root->right, res);

    if(root->left == NULL && root->right == NULL)
        res.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root) {
    vector<int> ans;

    if(root == NULL)
        return ans;

    ans.push_back(root->data);

    vector<int> res1, res2, res3;
    
    printLeftBoundary(root->left, res1);
    printLeaves(root->left, res2);
    printLeaves(root->right, res2);
    printRightBoundary(root->right, res3);

    for(auto i: res1)
        ans.push_back(i);
    for(auto i: res2)
        ans.push_back(i);
    for(auto i: res3)
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