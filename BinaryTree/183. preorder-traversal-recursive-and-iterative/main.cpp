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

void preorder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void preorderIterative(Node *node)
{
    if (root == nullptr)
        return;

    stack<Node *> stk;
    stk.push(node);

    while (!stk.empty())
    {
        Node *p = stk.top();
        stk.pop();

        cout << p->data << " ";

        if (p->right)
            stk.push(p->right);
        if (p->left)
            stk.push(p->left);
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

    preorder(root);
    cout << endl;

    preorderIterative(root);

    return 0;
}