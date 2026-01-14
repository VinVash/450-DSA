#include <bits/stdc++.h>
using namespace std;

TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int> mp) {
    if(inStart > inEnd || postStart > postEnd)
        return NULL;

    TreeNode* root = new TreeNode(postorder[postEnd]);

    int inRoot = mp[root->val];
    int numsLeft = inRoot - inStart;

    root->left = build(inorder, inStart, inRoot-1, postorder, postStart, postStart+numsLeft-1, mp);
    root->right = build(inorder, inRoot+1, inEnd, postorder, postStart+numsLeft, postEnd-1, mp);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() != postorder.size())
        return NULL;

    int n = inorder.size();
    map<int, int> mp;

    for(int i = 0; i < n; i++)
        mp[inorder[i]] = i;

    return build(inorder, 0, n-1, postorder, 0, n-1, mp);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}