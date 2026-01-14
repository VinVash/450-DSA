#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *next;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

bool searchInBST(BinaryTreeNode<int> *root, int x) {
	if(root == nullptr)
		return false;

    if(root->data == x) {
    	return true;
    } else if(root->data < x) {
    	searchInBST(root->right, x);
    } else {
    	searchInBST(root->left, x);
    }
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}