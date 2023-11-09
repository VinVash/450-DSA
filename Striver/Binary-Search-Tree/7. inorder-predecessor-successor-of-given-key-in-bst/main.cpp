#include <bits/stdc++.h>
using namespace std;

void inorder(BinaryTreeNode<int>* root, vector<int> &ans) {
    if(root == nullptr)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int val) {
    pre = NULL;
    suc = NULL;
 
    // set temp node as root
    Node* temp1 = root;
    while (temp1) {
        
        if (temp1->key > val) {
            suc = temp1;
            temp1 = temp1->left;
        }
        else
            temp1 = temp1->right;
    }
    Node* temp2 = root;
    while (temp2) {
        
        if (temp2->key < val) {
            pre = temp2;
            temp2 = temp2->right;
        }
        else
            temp2 = temp2->left;
    }

    // final ans are stored in pre and suc.
    return;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}