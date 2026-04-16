#include <bits/stdc++.h>
using namespace std;

struct Foo {
    int x;
    string s;

    Foo(int x, string s) : x(x), s(std::move(s)) {
        cout << "Foo ctor: " << x << ", " << this->s << endl;
    }

    ~Foo() {
        cout << "Foo dtor" << endl;
    }
};

void by_value(std::shared_ptr<int> p) {
    std::cout << "inside by_value: " << p.use_count() << "\n";
}

void by_ref(const std::shared_ptr<int>& p) {
    std::cout << "inside by_ref: " << p.use_count() << "\n";
}

class Node {
public:
    int value;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;  // Use weak_ptr to break circular references
    
    Node(int val) : value(val), next(nullptr) {}
    
    ~Node() {
        std::cout << "Destroying node with value: " << value << std::endl;
    }
};


int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // 1. copying a shared_ptr
    // shared_ptr<Foo> sp = make_shared<Foo>(42, "hello");
    // cout << "use_count = " << sp.use_count() << endl;

    // {
    //     auto a = sp;
    //     cout << "After copy, use_count = " << sp.use_count() << endl;
    //     cout << "After copy, use_count of a = " << a.use_count() << endl;

    // }

    // cout << "After scope, use_count = " << sp.use_count() << endl;

    // 2. passing shared_ptr by value vs by reference

    // auto p = std::make_shared<int>(42);
    // std::cout << "before calls: " << p.use_count() << "\n";

    // by_value(p);
    // std::cout << "after by_value: " << p.use_count() << "\n";

    // by_ref(p);
    // std::cout << "after by_ref: " << p.use_count() << "\n";


    // shared_ptr<Node> node1 = make_shared<Node>(1);
    // shared_ptr<Node> node2 = make_shared<Node>(2);
    
    // node1->next = node2;
    // node2->prev = node1;  // weak_ptr prevents circular reference
    
    // cout << "node1 ref count: " << node1.use_count() << endl;
    // cout << "node2 ref count: " << node2.use_count() << endl;

    std::shared_ptr<Foo> p = std::make_shared<Foo>(42, "hello");

    std::thread t1([&p]() mutable {
        auto local = p;
        // std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "Thread 1 done\n";
    });

    std::thread t2([&p]() mutable {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        p.reset();
        std::cout << "Thread 2 reset its copy\n";
    });

    t1.join();
    t2.join();


    return 0;
}