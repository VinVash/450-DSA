#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // 1. vector V/S list traversal
    // const int N = 10'000'000;
    // vector<int> v(N, 1);
    // list<int> l(N, 1);
    // auto t1 = chrono::high_resolution_clock::now();
    // long long sum1 = 0;
    // for (int x : v) sum1 += x;
    // auto t2 = chrono::high_resolution_clock::now();

    // long long sum2 = 0;
    // for (int x : l) sum2 += x;
    // auto t3 = chrono::high_resolution_clock::now();

    // cout << "Vector time: "
    //      << chrono::duration<double>(t2 - t1).count() << "\n";
    // cout << "List time:   "
    //      << chrono::duration<double>(t3 - t2).count() << "\n";

    
    // 2. insertion benchmark - vector v/s list
    // const int N = 1000000;
    // vector<int> v;
    // list<int> l;
    // auto t1 = chrono::high_resolution_clock::now();
    // for (int i = 0; i < N; i++)
    //     v.insert(v.begin(), i); // need to shift all elements after i
    // auto t2 = chrono::high_resolution_clock::now();

    // for (int i = 0; i < N; i++)
    //     l.insert(l.begin(), i);
    // auto t3 = chrono::high_resolution_clock::now();

    // cout << "Vector insert front: "
    //      << chrono::duration<double>(t2 - t1).count() << "\n";
    // cout << "List insert front:   "
    //      << chrono::duration<double>(t3 - t2).count() << "\n";


    // 3. iterator invalidation
    // vector<int> v;
    // v.reserve(2);

    // v.push_back(1);
    // v.push_back(2);

    // int* ptr = &v[0];  // pointer into vector

    // cout << "Before resize: " << *ptr << "\n";

    // v.push_back(3);   // may reallocate

    // // ptr is now potentially dangling
    // cout << "After resize (UB): " << *ptr << "\n";


    // 4. check vector capacity
    // vector<int> v;
    // cout << v.capacity() << endl;

    // 5. deque v/s vector - front insertion
    // const int N = 1'000'000;

    // vector<int> v;
    // deque<int> d;

    // auto t1 = chrono::high_resolution_clock::now();
    // for (int i = 0; i < N; i++)
    //     v.insert(v.begin(), i);
    // auto t2 = chrono::high_resolution_clock::now();

    // for (int i = 0; i < N; i++)
    //     d.push_front(i);
    // auto t3 = chrono::high_resolution_clock::now();

    // cout << "Vector front insert: "
    //      << chrono::duration<double>(t2 - t1).count() << "\n";
    // cout << "Deque push_front:   "
    //      << chrono::duration<double>(t3 - t2).count() << "\n";


    // 6. list splicing
    list<int> a = {1, 2, 3};
    list<int> b = {4, 5, 6};

    auto it = next(a.begin()); // points to 2

    // O(1) splice
    a.splice(it, b);

    for (int x : a) cout << x << " ";
    cout << "\n";

    return 0;
}