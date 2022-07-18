#include <bits/stdc++.h>
using namespace std;

Node* reverse (Node *head) {
    Node* newHead = nullptr; // newHead follows head.
    
    while(head != nullptr) {
        Node* temp = head->next;
        head->next = newHead;
        newHead = head;
        head = temp;
    }
    
    return newHead;
}

Node* addOneUtil(Node *head) {
    Node *temp = nullptr;
    Node *res = head; // original head is stored in the res variable.
    
     // initialising carry as the initial 1 in the question which we are supposed to add.
    int carry = 1, sum = 0;
    
    while(head) {
        sum = carry + head->data;
        
        carry = (sum >= 10) ? 1 : 0;
        
        sum = sum % 10;
        
        head->data = sum;
        
        temp = head;
        head = head->next;
    }
    
    if(carry > 0)
        temp->next = new Node(carry);
        
    return res; // original head.
}

Node* addOne(Node *head) {
    head = reverse(head);
    
    head = addOneUtil(head);
    
    return reverse(head);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}