#include <bits/stdc++.h>
using namespace std;

bool validBST(TreeNode* root, int mini, int maxi) {
    if(root == nullptr)
        return true;

    if(root->val >= mini && root->val <= maxi) {
        return validBST(root->left, mini, root->val) && validBST(root->right, root->val, maxi);
    } else {
        return false;
    }
}

bool isValidBST(TreeNode* root) {

    return validBST(root, INT_MIN, INT_MAX);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}