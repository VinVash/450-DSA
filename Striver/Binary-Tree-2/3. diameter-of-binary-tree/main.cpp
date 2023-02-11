#include <bits/stdc++.h>
using namespace std;

int height(TreeNode* node){
    if(node == NULL){
        return 0;
    }
    
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root){
    // base case
    if(root == NULL){
        return 0;
    }
    
    int lDia = diameterOfBinaryTree(root->left); // either in left
    int rDia = diameterOfBinaryTree(root->right); // either in right
    
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    
    int ans = max(lHeight + rHeight, max(lDia, rDia));
    
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}