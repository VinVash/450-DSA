#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *next;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while(!q.empty()) {
    	int n = q.size();

    	BinaryTreeNode<int> *first = nullptr;

    	while(n) {
	    	BinaryTreeNode<int> *node = q.front();
	    	q.pop();

	    	if(first != nullptr) {
	    		first->next = node;
	    	}

	    	if(node->left != nullptr) {
	    		q.push(node->left);
	    	}

	    	if(node->right != nullptr) {
	    		q.push(node->right);
	    	}

	    	first = node;

	    	n--;
	    }
	    first->next = nullptr;
    }

}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}