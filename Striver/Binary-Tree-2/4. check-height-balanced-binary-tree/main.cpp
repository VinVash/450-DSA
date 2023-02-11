#include <bits/stdc++.h>
using namespace std;

int height(TreeNode* node) {
	if(node == NULL)
		return 0;

	int lHeight = height(node->left);
	int rHeight = height(node->right);

	return 1 + lHeight + rHeight;
}

bool isBalanced(TreeNode* root) {
	int lHeight, rHeight;

	if(root == nullptr)
		return 1;

	lHeight = height(root->left);
	rHeight = height(root->right);

	if(abs(lHeight - rHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return 1;

	return 0;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}