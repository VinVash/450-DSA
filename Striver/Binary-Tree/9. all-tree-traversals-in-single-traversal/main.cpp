#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> pre;
 
    vector<int> post;
 
    vector<int> inor;
 
    stack<pair<BinaryTreeNode<int>*, int> > s;
    s.push(make_pair(root, 1));
 
    while (!s.empty()) {
 
        pair<BinaryTreeNode<int>*, int> p = s.top();
 
        if (p.second == 1) {
 
            s.top().second++;
 
            pre.push_back(p.first->data);
 
            if (p.first->left) {
 
                s.push(make_pair(
                    p.first->left, 1));
            }
        }

        else if (p.second == 2) {

            s.top().second++;
 
            inor.push_back(p.first->data);

            if (p.first->right) {
 
                s.push(make_pair(
                    p.first->right, 1));
            }
        }

        else {

            post.push_back(p.first->data);

            s.pop();
        }
    }

    vector<vector<int>> ans;

    ans.push_back(inor);
    ans.push_back(pre);
    ans.push_back(post);

    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}