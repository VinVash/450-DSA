#include <bits/stdc++.h>
using namespace std;

void solve() {    
}

struct Node {
    int val;

    vector<shared_ptr<Node>> neighbors;

    Node(int _val) : val(_val) {
        cout << "Constructed node " << val << endl;
    }

    ~Node() {
        cout << "Destroyed Node" << val << endl;
    }
};

class GraphCloner {
private:
    unordered_map<Node*, shared_ptr<Node>> vis;

public:
    shared_ptr<Node> cloneGraph(shared_ptr<Node> node) {
        if(!node) return nullptr;

        if(vis.find(node.get()) != vis.end()) {
            return vis[node.get()];
        }

        shared_ptr<Node> newNode = make_shared<Node>(node->val);

        vis[node.get()] = newNode;

        for(const auto& neighbor: node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return newNode;
    }
}

// we can fix the cycles by making the "back-pointers" into std::weak_ptr
// "back-pointers" are arrows that close the loop / complete the cycle.


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif




    return 0;
}