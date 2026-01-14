#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int getCount(Node *root, int k) {
        
    int count=0;
        
    queue<pair<Node*, int>>q;
    q.push({ root, 1 });
    while(!q.empty()){
        int n = q.size();
        while(n--){
            auto x = q.front();
            q.pop();
            Node *node = x.first;
            int level = x.second;
            if(!node->left && !node->right){
                  if(level <= k){
                      k = k - level;
                      count++;
                      if(k == 0) break;
                  } else break;
            }
            if(node->left)q.push({node->left, level+1});
            if(node->right)q.push({node->right, level+1});
        }
    }
    
    return count;
    
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(3);

    root->right = new Node(2);
    root->right->left = new Node(3);
    root->right->left->right = new Node(4);
    root->right->right = new Node(6);

    cout << getCount(root, 8) << endl;


    return 0;
}
