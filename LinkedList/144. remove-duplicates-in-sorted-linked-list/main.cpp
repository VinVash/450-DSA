#include <bits/stdc++.h>
using namespace std;

Node *removeDuplicates(Node *head) { // we need to remove (delete) the nodes, not just change the links.
    Node* to_free;
     
    /* do nothing if the list is empty */
    if (head == NULL)
        return nullptr;
 
    /* Traverse the list till last node */
    if (head->next != NULL) {
        if (head->data == head->next->data) {
            
            to_free = head->next;
            head->next = head->next->next;
            free(to_free);
            removeDuplicates(head);
        } else { //only advance if no deletion
            removeDuplicates(head->next);
        }
    }
    
    return head;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}