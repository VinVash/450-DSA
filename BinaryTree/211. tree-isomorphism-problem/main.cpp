#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;

	Node (int val) {
		this->data = val;
		this->left = this->right = nullptr;
	}
};

bool isIsomorphic(Node *n1, Node *n2) {
	if(n1 == nullptr && n2 == nullptr)
		return true;

	if(n1 == nullptr || n2 == nullptr)
		return false;

	if(n1->data != n2->data)
		return false;

	return (isIsomorphic(n1->left, n2->left) && isIsomorphic(n1->right, n2->right)) ||
			(isIsomorphic(n1->left, n2->right) && isIsomorphic(n1->right, n2->left));
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Node *n1 = new Node(1);
    n1->left        = new Node(2);
    n1->right       = new Node(3);
    n1->left->left  = new Node(4);
    n1->left->right = new Node(5);
    n1->right->left  = new Node(6);
    n1->left->right->left = new Node(7);
    n1->left->right->right = new Node(8);
 
    Node *n2 = new Node(1);
    n2->left         = new Node(3);
    n2->right        = new Node(2);
    n2->right->left   = new Node(4);
    n2->right->right   = new Node(5);
    n2->left->right   = new Node(6);
    n2->right->right->left = new Node(8);
    n2->right->right->right = new Node(7);
 
    if (isIsomorphic(n1, n2) == true)
       cout << "Yes";
    else
      cout << "No";

	return 0;
}