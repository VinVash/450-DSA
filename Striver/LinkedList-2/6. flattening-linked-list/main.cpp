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