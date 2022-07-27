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
// temporary node used to keep track of node returned from previous
// recursive call during backtrack.
Node *temp = nullptr;

Node* kthAncestorDFS(Node *root, int node , int &k) {
    if (!root)
        return NULL;
     
    if (root->data == node||
       (temp =  kthAncestorDFS(root->left,node,k)) ||
       (temp =  kthAncestorDFS(root->right,node,k)))
    {   // if something is being returned, i.e., if other than null,
    	//  anything is being returned, then the target has been found.
        if (k > 0)
            k--;
         
        else if (k == 0)
        {
            // print the kth ancestor
            cout<<"Kth ancestor is: "<<root->data;
             
            // return NULL to stop further backtracking
            return NULL;
        }
         
        // return current node to previous call
        return root;
    } else {
    	return nullptr;
    }
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	int k = 2;
	int node = 5;

	Node *parent = kthAncestorDFS(root, node, k);

	if(parent)
		cout << "-1" << endl;

	return 0;
}