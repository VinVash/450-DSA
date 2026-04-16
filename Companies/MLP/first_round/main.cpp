#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class scheduler {
    queue<function<void()>> q;
    bool running = false;

public:
    void schedule(function<void()> f) {
        q.push(std::move(f));

        // Only one execution loop allowed
        if (running) return;

        running = true;
        while (!q.empty()) {
            auto task = std::move(q.front());
            q.pop();
            task();
        }
        running = false;
    }
};

class stackscheduler {
    std::vector<std::function<void()>> stack;
    bool running = false;

public:
    void schedule(std::function<void()> fn) {
        stack.push_back(std::move(fn));

        // Prevent re-entrant execution
        if (running) return;

        running = true;
        while (!stack.empty()) {
            auto task = std::move(stack.back());
            stack.pop_back();
            task();
        }
        running = false;
    }
};

struct Stackscheduler2 {
    vector<function<void()>> st;

    void schedule(function<void()> f) {
        st.push_back(std::move(f));
    }

    void run() {
        while (!st.empty()) {
            auto f = std::move(st.back());
            st.pop_back();
            f();
        }
    }
};

struct FairScheduler {
    deque<function<void()>> dq;

    void schedule(function<void()> f) {
        dq.push_back(std::move(f));
    }

    void yield(function<void()> f) {
        dq.push_front(std::move(f));
    }

    void run() {
        while (!dq.empty()) {
            auto f = std::move(dq.front());
            dq.pop_front();
            f();
        }
    }
};


int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // Testing different schedulers - queue and stack based.
    // stackscheduler s;
    // Stackscheduler2 s; // without reentrancy guard

    // s.schedule([&]() {
    //     std::puts("Callback 1 start");

    //     s.schedule([&]() {
    //         std::puts("Callback 2 start");

    //         s.schedule([&]() {
    //             std::puts("Callback 3 start");
    //             std::puts("Callback 3 end");
    //         });

    //         std::puts("Callback 2 end");
    //     });

    //     s.schedule([&]() {
    //         std::puts("Callback 4 start");
    //         std::puts("Callback 4 end");
    //     });

    //     std::puts("Callback 1 end");
    // });

    // s.run();


    // Problem with BFS - queue scheduler
    // queue<function<void()>> q;

    // q.push([&]{
    //     cout << "Long task start\n";
    //     // Never-ending producer
    //     q.push([&]{ cout << "short task\n"; });
    //     q.push([&]{ cout << "short task\n"; });
    //     q.push([&]{ cout << "short task\n"; });
    //     cout << "Long task end\n";
    // });

    // while (!q.empty()) {
    //     auto f = std::move(q.front());
    //     q.pop();
    //     f();
    // }

    FairScheduler s;

    s.schedule([&]{
        cout << "Heavy start\n";
        s.yield([&]{
            cout << "Heavy resumed\n";
        });
        cout << "Heavy yield\n";
    });

    s.schedule([&]{
        cout << "Light task\n";
    });

    s.run();

    return 0;
}