#include <bits/stdc++.h>
using namespace std;

vector <int> bottomView(Node *root) {
    vector<int> res;
    
    if(root == nullptr)
        return res;
        
    queue<Node *> q;
    queue<int> hdq; // horizontal distance queue.
    map<int, int> m;
    int hd = 0;
    
    q.push(root);
    hdq.push(hd);
    
    while(q.size()) {
        m[hd] = root->data;
        
        if(root->left) {
			q.push(root->left);
			hdq.push(hd-1);
		}
                
		if(root->right) {
			q.push(root->right);
			hdq.push(hd+1);
		}
		
		q.pop();
		hdq.pop();
		
		root = q.front();
		hd = hdq.front();
    }
    
    for(auto i = m.begin(); i != m.end(); i++)
        res.push_back(i->second);
        
    return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	return 0;
}