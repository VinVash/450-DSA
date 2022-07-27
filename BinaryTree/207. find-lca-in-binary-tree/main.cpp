#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;

	Node(int val) {
		this->data = val;
		this->left = this->right = nullptr;
	}
};

/* FIRST APPROACH */

Node *findLCA(Node *node, int n1, int n2) {
	if(node == nullptr) return nullptr;

	 // the first element to be found is the lca.
	if(node->data == n1 || node->data == n2)
		return node;

	Node *left_lca = findLCA(node->left, n1, n2);
	Node *right_lca = findLCA(node->right, n1, n2);

	// one key is present in left subtree and the other is present in right subtree,
	// therefore the current node is the LCA.
	if(left_lca && right_lca)
		return node;

	return (left_lca != nullptr) ? left_lca : right_lca;
}

/* SECOND APPROACH */

Node *findLCAUtil(Node *node, int n1, int n2, bool &v1, bool &v2) {
	if(node == nullptr)
		return nullptr;

	if(node->data == n1) {
		v1 = true;
		return node;
	}
	if(node->data == n2) {
		v2 = true;
		return node;
	}

	Node *left_lca = findLCAUtil(node->left, n1, n2, v1, v2);
	Node *right_lca = findLCAUtil(node->right, n1, n2, v1, v2);

	if(left_lca && right_lca)
		return node;

	return (left_lca != nullptr) ? left_lca : right_lca;
}

bool find(Node *node, int k) {
    // Base Case
    if (node == nullptr)
        return false;
 
    // If key is present at root, or in left subtree or right subtree,
    // return true;
    if (node->data == k || find(node->left, k) ||  find(node->right, k))
        return true;
 
    // Else return false
    return false;
}

Node *findLCA2(Node *node, int n1, int n2) {
	bool v1 = false, v2 = false;

	Node *lca = findLCAUtil(node, n1, n2, v1, v2);

	if(v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
		return lca;

	return nullptr;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->data;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->data;

    cout << "\n\n";

    cout << "LCA(4, 5) = " << findLCA2(root, 4, 5)->data;
    cout << "\nLCA(4, 6) = " << findLCA2(root, 4, 6)->data;
    cout << "\nLCA(3, 4) = " << findLCA2(root, 3, 4)->data;
    cout << "\nLCA(2, 4) = " << findLCA2(root, 2, 4)->data;

	return 0;
}