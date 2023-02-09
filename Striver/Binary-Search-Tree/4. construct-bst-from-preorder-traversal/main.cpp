#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    
    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode* build(vector<int>& A, int& i, int bound) {
    if(i == A.size() || A[i] > bound)
        return NULL;

    TreeNode* root = new TreeNode(A[i]);
    i++;
    root->left = build(A, i, root->val);
    root->right = build(A, i, bound);
    
    return root;
}

TreeNode* bstFromPreorder(vector<int> &A) {
    int i = 0;
    return build(A, i, INT_MAX); // INT_MAX is passed as the upper bound here.
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    cout << "Hello World" << endl;

	return 0;
}