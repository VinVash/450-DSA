#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr;
	}
};

void postorder(Node *root)
{
	if (root == nullptr)
		return;

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

void postorderIterative(Node *root)
{
	if (root == nullptr)
		return;

	stack<Node *> stk;
	stk.push(root);

	stack<int> out; // stack to store postorder traversal.

	while (!stk.empty())
	{
		Node *p = stk.top();
		stk.pop();

		out.push(p->data);

		if (p->left)
			stk.push(p->left);

		if (p->right)
			stk.push(p->right);
	}

	while (!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	postorder(root);
	cout << endl;

	postorderIterative(root);

	return 0;
}