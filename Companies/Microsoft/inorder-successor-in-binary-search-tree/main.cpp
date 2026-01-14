#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right, *parent;

	Node(int val) {
		this->data = val;
		this->left = this->right = this->parent = nullptr;
	}
};

Node* inorderSuccessor(Node *root, Node *node) {
	if(node->right)
		return minValue(node->right);

	// if node->right is NULL.
	Node *p = node->parent;
	while(p != nullptr && node == p->right) {
		node = p;
		p = p->parent;
	}

	return p;
}

Node* inorderSuccessor2(Node *root, Node *node) {
	if(node->right)
		return minValue(node->right);

	Node *succ = nullptr; // successor.

	while(root) {
		if(node->data < root->data) {
			succ = root;
			root = root->left;
		} else if(node->data > root->data)
			root = root->right;
		else
			break;
	}

	return succ;
}

Node* minValue(Node *node) {
	Node *current = node;

	while(current->left) {
		current = current->left;
	}

	return current;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}