#include <bits/stdc++.h>
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr)
        return nullptr;

    if(root->val == p->val || root->val == q->val) 
        return root; // the first element to be found is the LCA.

    TreeNode* left_lca = lowestCommonAncestor(root->left, p, q);
    TreeNode* right_lca = lowestCommonAncestor(root->right, p, q);

    if(left_lca && right_lca)
        return root;

    return (left_lca != nullptr) ? left_lca : right_lca;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}