#include <bits/stdc++.h>
using namespace std;

void inorder(BinaryTreeNode<int>* root, vector<int> &ans) {
    if(root == nullptr)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    vector<int> ans;

    inorder(root, ans);

    int pos = -1;

    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == key) {
            pos = i;
            break;
        }   
    }

    int first = pos-1;
    int second = pos+1;
    
    if(second == ans.size())
        second = -1;

    int el1 = -1, el2 = -1;

    if(first != -1)
        el1 = ans[first];

    if(second != -1)
        el2 = ans[second];

    pair<int, int> res = make_pair(el1, el2);
    return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}