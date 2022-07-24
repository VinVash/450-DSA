#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

struct Node *newNode(int item) {
    struct Node *temp = (struct Node *)malloc(
                        sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void leftViewUtil(Node *root, int level, int *max_level) {
	if(root == nullptr) return;

	if(*max_level < level) {
		cout << root->data << " ";
		*max_level = level;
	}

	leftViewUtil(root->left, level+1, max_level);
	leftViewUtil(root->right, level+1, max_level);
}

void leftView(Node *root) {
	int max_level = 0;
	leftViewUtil(root, 1, &max_level);
}

vector<int> printLeftView(Node *root) {
    vector<int> res; // output array.
    
    if(!root)
        return res;
        
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()) {
        int n = q.size();
        
        for(int i = 1; i <= n; i++) {
            Node *p = q.front();
            q.pop();
            
            if(i == 1)
                res.push_back(p->data);
                
            if(p->left)
                q.push(p->left);
                
            if(p->right)
                q.push(p->right);
        }
    }
    
    return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
 
    leftView(root);
    cout << endl;

    printLeftView(root);

	return 0;
}