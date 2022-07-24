#include <bits/stdc++.h>
using namespace std;

vector <int> zigZagTraversal(Node* root) {
    vector<int > ans;
    if(root == nullptr)
        return ans;
        
    queue<Node*> q;
    q.push(root);
    bool flag = false;
 
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++){
            Node* node = q.front();
            q.pop();
            level.push_back(node->data);
 
            if(node->left != NULL) {q.push(node->left);}
            if(node->right != NULL) {q.push(node->right);}
 
        }
        flag = !flag ;  
        if(flag == false){
            reverse(level.begin() , level.end()) ;           
        }
        for(int i = 0 ; i < level.size() ; i++) {
          ans.push_back(level[i]) ;
        }
         
    }
    return ans ;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}