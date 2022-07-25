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

bool areMirror(Node *a, Node *b) {
	if(a == nullptr && b == nullptr)
		return true;

	if(a == nullptr || b == nullptr) // if only one is null.
		return false;

	return a->data == b->data && areMirror(a->left, b->right) && areMirror(a->right, b->left);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Node *a = new Node(1);
    Node *b = new Node(1);
    a->left = new Node(2);
    a->right = new Node(3);
    a->left->left  = new Node(4);
    a->left->right = new Node(5);
 
    b->left = new Node(3);
    b->right = new Node(2);
    b->right->left = new Node(5);
    b->right->right = new Node(4);
 
    areMirror(a, b) ? cout << "Yes" : cout << "No";
    cout << endl;

	return 0;
}