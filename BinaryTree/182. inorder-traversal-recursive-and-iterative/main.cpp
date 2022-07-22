#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;

	Node(int data) {
		this->data = data;
		this->left = this->right = nullptr;
	}
};

// Recursive inorder.
void inorder(Node *root) {
	if(root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void inorderIterative(Node *root) {
	if(root == nullptr)
		return;
	
	stack<Node *> stack;

	Node* curr = root;

	while(!stack.empty() || curr != nullptr) {
		if(curr != nullptr) {
			stack.push(curr);
			curr = curr->left;
		} else {
			curr = stack.top();
			stack.pop();
			cout << curr->data << " ";

			curr = curr->right;
		}
	}
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    inorder(root);
    cout << endl;

    inorderIterative(root);

	return 0;
}