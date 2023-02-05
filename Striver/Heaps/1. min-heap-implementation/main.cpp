#include <bits/stdc++.h>
using namespace std;

struct PriorityQueue {
private:
	vector<int> A;

	// return parent of A[i]
	int PARENT(int i) {
		return (i-1) / 2;
	}

	// return left child of A[i]
	int LEFT(int i) {
		return (2*i + 1);
	}


	// return right child of A[i]
	int RIGHT(int i) {
		return (2*i + 2);
	}

	// Recursive heapify_down function
	void heapify_down(int i) {

		// get left and right child index of A[i]
		int left = LEFT(i);
		int right = RIGHT(i);

		int smallest = i;

		// compare A[i] with left and right child and find the smallest
		if(left < size() && A[left] < A[i]) {
			smallest = left;
		}

		if(right < size() && A[right] < A[i]) {
			smallest = right;
		}

		// swap with the smallest child and call heapify_down on the child
		if(smallest != i) {
			swap(A[i], A[smallest]);
			heapify_down(smallest);
		}
	}

	void heapify_up(int i) {

		// check if the node at index i, and its parent violate the heap property.
		if(i && A[PARENT(i)] > A[i]) {
			swap(A[i], A[PARENT(i)]);

			heapify_up(PARENT(i));
		}
	}

public:
	unsigned int size() {
		return A.size();
	}

	bool empty() {
		return size() == 0;
	}

	void push(int key) {
		A.push_back(key);

		int index = size() - 1;
		heapify_up(index);
	}

	void pop() {
		try {
			if(size() == 0) {
				throw out_of_range("Vector<X>::at() : index is out of range(Heap underflow)");
			}

			A[0] = A.back();
			A.pop_back();

			heapify_down(0);
		}

		catch (const out_of_range &oor) {
			cout << endl << oor.what();
		}
	}

	int top() {
		try {
			if(size() == 0) {
				throw out_of_range("Vector<X>::at() : index is out of range(Heap underflow)");
			}

			return A.at(0);
		}

		catch (const out_of_range &oor) {
			cout << endl << oor.what();

			return 0;
		}
	}
};

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	PriorityQueue pq;
 
    // Note: The element's value decides priority
 
    pq.push(3);
    pq.push(2);
    pq.push(15);
 
    cout << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    pq.push(5);
    pq.push(4);
    pq.push(45);
 
    cout << endl << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << endl << boolalpha << pq.empty();
 
    pq.top();    // top operation on an empty heap


	return 0;
}