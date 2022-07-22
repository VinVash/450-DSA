void clear(queue<Node *> &q ) {
   std::queue<Node *> empty;
   std::swap(q, empty);
}

vector<int> reverseLevelOrder(Node *root) {
    vector<vector<int>> rlot;
    vector<int> temp;
    
    queue<Node *> q;
    queue<Node *> secondq;
    
    q.push(root);
    
    while(!q.empty()) {
        while(!q.empty()) {
            temp.push_back(q.front()->data);
            Node *p = q.front();
            q.pop();
            if(p->left)
                secondq.push(p->left);
            if(p->right)
                secondq.push(p->right);
        }
        
        rlot.push_back(temp);
        temp.clear();
        q = secondq;
        clear(secondq);
    }
    
    vector<int> res;
    reverse(rlot.begin(), rlot.end());
    
    for(auto vec: rlot) {
        for(auto i: vec)
            res.push_back(i);
    }
    
    return res;
}