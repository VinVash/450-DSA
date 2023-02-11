#include <bits/stdc++.h>
using namespace std;

bool areMirror(TreeNode* a, TreeNode* b) {
    if(a == NULL && b == NULL) // if both are NULL.
        return true;

    if(a == NULL || b == NULL) // if only one is NULL.
        return false;

    return a->val == b->val && areMirror(a->left, b->right) && areMirror(a->right, b->left);
}

bool isSymmetric(TreeNode* root) {
    return areMirror(root->left, root->right);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}