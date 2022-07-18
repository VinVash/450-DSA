#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;
};

void createLinkedList(Node* head, Node* last, vector<int> &arr) {
	Node* temp;
	for (int i = 1; i < arr.size(); i++) {
 
        // Create a temporary Node
        temp = new Node;
 
        // Populate temporary Node
        temp->data = arr[i];
        temp->next = nullptr;
 
        // last's next is pointing to temp
        last->next = temp;
        last = temp;
    }
}

void displayLinkedList(Node *p) {

	while(p != nullptr) {
		cout << p->data << " -> ";
		p = p->next;
	}
	cout << endl;
}

void displayLinkedListRecursive(Node *p) {
	if(p != nullptr) {
		cout << p->data << " -> ";
		displayLinkedListRecursive(p->next);
	}
}
 
int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
 	
 	int n; cin >> n;
 	vector<int> nums(n);

 	for(int i = 0; i < n; i++)
 	    cin >> nums[i];

 	// till here vector is initialised and inputted.
 
    Node* head = new Node;
    Node* last = nullptr;
 
    head->data = nums[0];
    head->next = nullptr;
    last = head;
 
    // Create a Linked List
    createLinkedList(head, last, nums);
    cout << last->data << endl; // still at first, because a copy was made in createLinkedList function
 	cout << head->next->data << endl;

    // Display Linked List
    displayLinkedList(head); // displayLinkedList function makes a copy of the pointer head.
 	displayLinkedListRecursive(head);

    return 0;
}