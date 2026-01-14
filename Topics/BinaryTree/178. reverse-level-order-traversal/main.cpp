void clear(queue<Node *> &q ) {
   std::queue<Node *> empty;
   std::swap(q, empty);
}

vvector<int> reverseLevelOrder(Node *root) {
    vector<vector<int>> rlot;
    vector<int> temp;
    
    queue<Node *> q;
    
    q.push(root);
    
    while(!q.empty()) {
        int n = q.size();
        
        while(n) {
            Node *p = q.front();
            q.pop();
            
            temp.push_back(p->data);
            
            if(p->left)
                q.push(p->left);
                
            if(p->right)
                q.push(p->right);
            
            n--;
        }
        rlot.push_back(temp);
        temp.clear();
    }
    
    reverse(rlot.begin(), rlot.end());
    
    vector<int> res;
    
    for(auto vec: rlot) {
        for(auto i: vec)
            res.push_back(i);
    }
    
    return res;
}