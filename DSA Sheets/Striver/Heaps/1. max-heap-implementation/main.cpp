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

	// Recursive heapify down algorithm
	void heapify_down(int i) {

		// get left and right child index of A[i]
		int left = LEFT(i);
		int right = RIGHT(i);

		int largest = i;
		// compare A[i] with its left and right child and find the largest value
		if(left < size() && A[left] > A[i]) {
			largest = left;
		}

		if(right < size() && A[right] > A[i]) {
			largest = right;
		}

		// swap with a child having greater value and call heapify_down on the child
		if(largest != i) {
			swap(A[i], A[largest]);
			heapify_down(largest); // passing the index here.
		}
	}

	// Recursive heapify up algorithm
	void heapify_up(int i) {
		
		// check if the node at i and its parent violates the heap property
		if(i && A[PARENT(i)] < A[i]) {

			// swap the two if the heap property is violated
			swap(A[i], A[PARENT(i)]);

			// call heapify_up on the parent.
			heapify_up(PARENT(i)); // passing the index here.
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

			// replce the root of the heap with the last element of the vector
			A[0] = A.back();
			A.pop_back();

			// call heapify_down on the root node
			heapify_down(0);
		}

		// catch and print the exception
		catch (const out_of_range &oor) {
			cout << endl << oor.what();
		}
	}

	int top()  {
		try {
			if(size() == 0) {
				throw out_of_range("Vector<X>::at() : index is out of range(Heap underflow)");
			}

			// return the top element of the heap, i.e., present at index 0.
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

    pq.top(); // top operation on an empty heap.

	return 0;
}