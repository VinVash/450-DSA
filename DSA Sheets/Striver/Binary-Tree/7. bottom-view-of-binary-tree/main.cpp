#include <bits/stdc++.h>
using namespace std;

vector <int> bottomView(Node *root) {
        
    vector<int> res;
    
    queue<Node*> q;
    queue<int> hdq;
    map<int, int> mp;
    
    q.push(root);
    hdq.push(0);
    
    while(!q.empty()) {
        Node* p = q.top();
        q.pop();
        int hd = hdq.top();
        hdq.pop();
        
        m[hd] = p->data;
        
        if(root->left) {
            q.push(root->left);
            hdq.push(hd-1);
        }
        
        if(root->right) {
            q.push(root->right);
            hdq.push(hd+1);
        }
    }

    for(auto i = m.begin(); i != m.end(); i++) {
    	ans.push_back(i->second);
    }

    return res;
    
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}