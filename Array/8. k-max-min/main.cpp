#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int* harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    MinHeap(int a[], int size); // Constructor
    void MinHeapify(int i); // To minheapify subtree rooted with index i
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
 
    int extractMin(); // extracts root (minimum) element
    int getMin() { return harr[0]; } // Returns minimum
};

MinHeap::MinHeap(int a[], int size) {
    heap_size = size;
    harr = a; // store address of array
    int i = (heap_size - 1) / 2;
    while (i >= 0) {
        MinHeapify(i);
        i--;
    }
}

int MinHeap::extractMin() {
    if (heap_size == 0)
        return INT_MAX;
 
    // Store the minimum value.
    int root = harr[0];
 
    // If there are more than 1 items, move the last item to root
    // and call heapify.
    if (heap_size > 1) {
        harr[0] = harr[heap_size - 1];
        MinHeapify(0);
    }
    heap_size--;
 
    return root;
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[smallest])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

int kthSmallestByHeap(vector<int> &nums, int k) {
    MinHeap mh(nums, k);

    for(int i = 0; i < k-1; i++)
        mh.extractMin();

    return mh.getMin();
}

int kthSmallest(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[k-1];
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    vector<int> nums {5, 4, 3, 2, 1};
    cout << kthSmallest(nums, 3);
    cout << kthSmallestByHeap(nums, nums.size(), 3);

	return 0;
}