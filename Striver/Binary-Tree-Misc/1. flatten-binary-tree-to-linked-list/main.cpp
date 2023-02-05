#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *solve(TreeNode *root) {
    if(root == NULL)
        return NULL;

    TreeNode *leftTail = solve(root->left);
    TreeNode *rightTail = solve(root->right);

    if(leftTail) {
        leftTail->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }

    if(rightTail) {
        return rightTail;    
    } else if(leftTail) {
        return leftTail;
    } else {
        return root;
    }
}

void flatten(TreeNode* root) {
    solve(root);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}