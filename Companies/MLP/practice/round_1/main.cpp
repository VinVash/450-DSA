#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(T val) {
    std::cout << "Generic: " << val << "\n";
}

// Specialization for char
template <>
void print<char>(char val) {
    std::cout << "Specialized (Char): " << val << "\n";
}

struct Node {
    int val;

    vector<shared_ptr<Node>> neighbors;

    Node(int _val) : val(_val) {
        cout << "Constructed node " << val << endl;
    }

    ~Node() {
        cout << "Destroyed Node " << val << endl;
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
};

// we can fix the cycles by making the "back-pointers" into std::weak_ptr
// "back-pointers" are arrows that close the loop / complete the cycle.

// However, in a generic graph where any node can point to any node,
// you cannot easily decide which one is the "back" pointer.

// The DSA Solution: For complex graph structures like this,
// you must manually break the cycle before destruction.





template <typename T>
class SharedPtr {
private:
    T* ptr; // pointer to the managed object
    atomic<int>* ref_count; // pointer to the reference count

    void release() {
        if(ref_count) {
            if(ref_count->fetch_sub(1) == 1) {
                delete ptr;
                delete ref_count;
                cout << "Resource destroyed" << endl;
            }
        }
    }

public:
    SharedPtr() : ptr(nullptr), ref_count(nullptr) {}

    // Parameterized constructor
    explicit SharedPtr(T* p): ptr (p) {
        if(ptr) {
            ref_count = new atomic<int>(1);
        } else {
            ref_count = nullptr;
        }
    }

    // Copy constructor
    SharedPtr(const SharedPtr& other) {
        ptr = other.ptr;
        ref_count = other.ref_count;
        if(ref_count) {
            ref_count->fetch_add(1); // increment count
        }
    }

    // Move constructor
    SharedPtr(SharedPtr&& other) noexcept {
        ptr = other.ptr;
        ref_count = other.ref_count;

        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    // Copy Assignment operator
    SharedPtr& operator=(const SharedPtr& other) {
        if(this != &other) {
            release(); // clean up current resource

            ptr = other.ptr;
            ref_count = other.ref_count;

            if(ref_count) {
                ref_count->fetch_add(1);
            }
        }

        return *this;
    }

    // Move Assignment operator
    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if(this != &other) {
            release();

            ptr = other.ptr;
            ref_count = other.ref_count;

            other.ptr = nullptr;
            other.ref_count = nullptr;
        }

        return *this;
    }

    // Destructor
    ~SharedPtr() {
        release();
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    // Utility: Get current reference count
    int use_count() const {
        return (ref_count) ? ref_count->load() : 0;
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    print(1);
    print("Hello");
    print(12.5);
    print('a');


    return 0;
}