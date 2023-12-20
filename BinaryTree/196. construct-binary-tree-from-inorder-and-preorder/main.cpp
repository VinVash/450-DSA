#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    char data;
    node* left;
    node* right;
};
 
/* Prototypes for utility functions */
TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mp) {
    if(preStart > preEnd || inStart > inEnd)
        return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);

    int inRoot = mp[root->val];
    int numsLeft = inRoot - inStart;

    root->left = build(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, mp);
    root->right = build(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, mp);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size();

    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[inorder[i]]=i;
    }

    return build(preorder, 0, n-1, inorder, 0, n-1, mp);
}
 
/* Driver code */
int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    node* root = buildTree(in, pre, 0, len - 1);
 
    /* Let us test the built tree by
    printing Inorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}
