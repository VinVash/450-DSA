#include <bits/stdc++.h>
using namespace std;

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q) {
	
    if(root->data > P->data && root->data > Q->data)
        return LCAinaBST(root->left, P, Q);

    if(root->data < P->data && root->data < Q->data)
        return LCAinaBST(root->right, P, Q);

    return root;
    
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}