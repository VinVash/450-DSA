#include <bits/stdc++.h>
using namespace std;

TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> mp) {
    if(preStart > preEnd || inStart > inEnd)
        return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);

    int inRoot = mp[root->val]; // index of the element in inorder array.
    int numsLeft = inRoot - inStart;

    root->left = build(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, mp);
    root->right = build(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, mp);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size();
    map<int, int> mp;

    for(int i = 0; i < n; i++)
        mp[inorder[i]] = i;

    TreeNode* root = build(preorder, 0, n-1, inorder, 0, n-1, mp);
    return root;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}