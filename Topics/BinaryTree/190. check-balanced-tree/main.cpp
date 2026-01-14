#include <bits/stdc++.h>
using namespace std;

int height(Node *node) {
    if(node == nullptr)
        return 0;
        
    else {
        int lDepth = height(node->left);
        int rDepth = height(node->right);
        
        return 1 + max(lDepth, rDepth);
    }
}

bool isBalanced(Node *root) {
    int lh;
    int rh;
  
    if (root == NULL)
        return 1;
  
    /* Get the height of left and right sub trees */
    lh = height(root->left);
    rh = height(root->right);
  
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
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