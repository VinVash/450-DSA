#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int hd;
    int data;
};

Node *newNode(int key)
{
    Node *node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}

vector<int> topView(Node *root)
{
    vector<int> res; // output array.

    if (!root)
        return res;

    queue<Node *> q;
    queue<int> hdq; // horizontal distance queue, stores the hd of corresponding nodes in q.
    map<int, int> m;
    int hd = 0; // initialise hd of root as 0.

    q.push(root);
    hdq.push(hd);

    while (!q.empty())
    {
        root = q.front();
        q.pop();

        hd = hdq.front();
        hdq.pop();

        if (m.count(hd) == 0) // if it is already non-zero, then it has already the node which is visible from top.
            m[hd] = root->data;

        if (root->left)
        {
            q.push(root->left);
            hdq.push(hd - 1);
        }

        if (root->right)
        {
            q.push(root->right);
            hdq.push(hd + 1);
        }
    }

    for (auto i = m.begin(); i != m.end(); i++)
        res.push_back(i->second);

    return res;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);

    topView(root);

    return 0;
}