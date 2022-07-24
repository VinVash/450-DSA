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

void diagonalTraversal(Node *root) {
    if(!root) return;

    queue<Node *> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();
        vector<int> temp;

        for(int i = 0; i < n; i++) {
            Node *p = q.front();
            q.pop();

            while(p) {
                cout << p->data << " ";

                if(p->left)
                    q.push(p->left);

                p = p->right;
            }
        }
        cout << endl;
    }
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    return 0;
}