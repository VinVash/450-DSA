#include <bits/stdc++.h>
using namespace std;

void changeTree(BinaryTreeNode < int > * root) {
    if(root == NULL)
        return;

    int childSum = 0;
    if(root->left)
        childSum += root->left->data;
    if(root->right)
        childSum += root->right->data;

    if(childSum >= root->data)
        root->data = childSum;
    else { // set the data of one child as the root's data.
        if(root->left)
            root->left->data = root->data;
        else if(root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left)
        total += root->left->data;
    if(root->right)
        total += root->right->data;
    if(root->left || root->right)
        root->data = total;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}