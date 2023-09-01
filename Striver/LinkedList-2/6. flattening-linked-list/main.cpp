#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

Node* flattenLinkedList(Node* head) {
    Node *temp = head;
    Node *next = temp->next;
    
    while(next != nullptr) {
        while(temp->child != nullptr) {
            temp->next = temp->child;
            temp = temp->child;
        }
        temp->next = next;
        temp = next;
        next = next->next;
    }
    
    while(temp->child != nullptr) {
        temp->next = temp->child;
        temp = temp->child;
    }
    
    return head;
}

// Second question: Flattening a Linked List
/* 
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.
*/

/*
// We can use a priority queue.

struct mycomp {
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};

void flatten(Node* root) {
    priority_queue<Node*, vector<Node*>, mycomp> p;
    // pushing main link nodes into priority_queue.
    while (root != NULL) {
        p.push(root);
        root = root->next;
    }

    // Extracting the minimum node
    // while priority queue is not empty
    while (!p.empty()) {

        // extracting min
        auto k = p.top();
        p.pop();

        // printing  least element
        cout << k->data << " ";
        if (k->bottom)
            p.push(k->bottom);
    }
}
*/

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Node *head = new Node(1);
    head->child = new Node(2);
    head->child->child = new Node(3);

    head->next = new Node(4);
    head->next->child = new Node(5);
    head->next->child->child = new Node(6);

    head->next->next = new Node(7);
    head->next->next->child = new Node(8);

    head->next->next->next = new Node(9);
    head->next->next->next->child = new Node(10);

    head->next->next->next->next = new Node(11);

    Node *ans = flattenLinkedList(head);

    Node *temp = ans;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}