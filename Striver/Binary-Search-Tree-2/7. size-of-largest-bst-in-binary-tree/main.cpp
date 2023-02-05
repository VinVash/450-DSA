#include <bits/stdc++.h>
using namespace std;

struct SubTreeInfo {

    int min, max; // stores the min, max value of subtree.
    
    int size; // stores the size of subtree.
 
    bool isBST; // whether the subtree is BST or not.
 
    // constructor
    SubTreeInfo(int min, int max, int size, bool isBST)
    {
        this->min = min;
        this->max = max;
        this->size = size;
        this->isBST = isBST;
   }

};

SubTreeInfo* findLargestBST(TreeNode<int>* root)
{
    // Base case: empty tree
    if (root == nullptr) {
        return new SubTreeInfo(INT_MAX, INT_MIN, 0, true);
    }
 
    SubTreeInfo* left = findLargestBST(root->left);
    SubTreeInfo* right = findLargestBST(root->right);
 
    SubTreeInfo* info = nullptr;

    if (left->isBST && right->isBST &&
        (root->data > left->max && root->data < right->min)) {
        info = new SubTreeInfo(min(root->data, min(left->min, right->min)),
                        max(root->data, max(left->max, right->max)),
                        left->size + 1 + right->size,
                        true);
    }
    else {
        // If a binary tree rooted under the current root is not a BST,
        // return the largest BST size in its left and right subtree
 
        info = new SubTreeInfo(0, 0,
                        max(left->size, right->size),
                        false);
    }
 
    // deallocate the memory for the left and right subtrees info node
    delete(left), delete(right);
 
    return info;
}

int largestBST(TreeNode<int>* root) {
    SubTreeInfo *info = findLargestBST(root);

    return info->size;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}