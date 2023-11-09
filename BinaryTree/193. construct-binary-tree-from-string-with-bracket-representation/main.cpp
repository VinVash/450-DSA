#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;

	Node(int val)
	{
		this->data = val;
		this->left = this->right = nullptr;
	}
};

void preorder(Node *root)
{
	if (!root)
		return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void preorderIterative(Node *node)
{
	if (!node)
		return;

	stack<Node *> stk;
	stk.push(node);

	while (stk.size())
	{
		Node *p = stk.top();
		stk.pop();

		cout << p->data << " ";

		if (p->right)
			stk.push(p->right);
		if (p->left)
			stk.push(p->left); // this will come first, because it is inserted into the stack later.
	}

	cout << endl;
}

int findIndex(string str, int l, int r)
{
	if (l > r)
		return -1;

	stack<char> stk;

	for (int i = l; i <= r; i++)
	{
		if (str[i] == '(')
			stk.push(str[i]);
		else if (str[i] == ')')
		{
			if (stk.top() == '(')
			{
				stk.pop();

				if (stk.empty())
					return i; // found out the closing paranthesis index.
			}
		}
	}

	return -1; // if the closing index hasn't been found till now.
}

Node* treeFromString(string str, int l, int r)
{
	if (l > r)
		return nullptr;

	Node* root = new Node(str[l] - '0');

	int index = -1; // for the closing bracket.
	// If only one element is present, then index will remain -1
	// even after the next if statement, therefore,
	// only root will be returned with its left and right nodes as null.

	if (l + 1 <= r && str[l + 1] == '(')
		index = findIndex(str, l + 1, r);

	if (index != -1)
	{
		root->left = treeFromString(str, l + 2, index - 1);
		root->right = treeFromString(str, index + 2, r - 1);
	}

	return root;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str = "4(2(3)(1))(6(5))";
	Node *root = treeFromString(str, 0, str.length() - 1);
	// preorder(root);
	preorderIterative(root);

	return 0;
}